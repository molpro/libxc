(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)

$include "scaling.mpl"

(* parameters *)
wpbeh_A :=  1.0161144:
wpbeh_B := -0.37170836:
wpbeh_C := -0.077215461:
wpbeh_D :=  0.57786348:
(* E is fixed by the requirement that EG is regular at s = 0, i.e.
   3*Pi/4 + Ga(0) = 0 (else EG_orig carries a spurious ~epsilon/s^2 pole that
   the series branch drops, making the two branches disagree by that epsilon
   and the low-gradient junction discontinuous).  Solving Ga(0) = 0 for E:
     Ga(0) = sqrt(Pi)*(15 E + 6 C D + 4 B D^2 + 8 A D^3)/(16 D^(7/2))
             - 3*Pi/4*sqrt(A).
   The published float -0.051955731 satisfies this only to ~1.4e-8; compute it
   exactly instead (cf. Fc1/Fc2 below, likewise derived from A,B,C,D). *)
wpbeh_E := (12*sqrt(Pi)*(sqrt(wpbeh_A) - 1)*wpbeh_D^(7/2)
  - (6*wpbeh_C*wpbeh_D + 4*wpbeh_B*wpbeh_D^2 + 8*wpbeh_A*wpbeh_D^3))/15:

(*
 Note that kF has a 6 and not a 3 as it should in principle
 be. This is because the HSE formula, if one would take the papers
 seriously, does not fulfill the spin sum-rule. This is probably
 an oversight from them. So, we have to choose, either a 6 or a 3.

 Nwchem seems to have the factor of 6, but VASP and espresso have
 a 3. This would amount to rescaling omega by a factor of
 cbrt(2). We follow the quantum chemistry community and put the 6.
*)

(* Cutoff criterion below which to use polynomial expansion *)
EGscut     := 0.08:
wcutoff    := 14:
expfcutoff := 700:

(* first let us calculate H(s) *)
wpbeh_Ha1 := 0.00979681:
wpbeh_Ha2 := 0.0410834:
wpbeh_Ha3 := 0.187440:
wpbeh_Ha4 := 0.00120824:
wpbeh_Ha5 := 0.0347188:
wpbeh_H := s ->
  + (wpbeh_Ha1*s^2 + wpbeh_Ha2*s^4)
  / (1 + wpbeh_Ha3*s^4 + wpbeh_Ha4*s^5 + wpbeh_Ha5*s^6):

(*
  Now we calculate F(s).  Fc1/Fc2 are determined by A,B,C,D; the published
  floats (6.4753871, 0.47965830) round them to ~6e-9 / ~8e-9, which enters EG
  at O(s^2) (its constant term) and, like the E rounding above, makes the
  low-gradient junction discontinuous.  Use the exact expressions.
*)
wpbeh_Fc1 := 4*wpbeh_A^2/(9*wpbeh_C) + (wpbeh_B - wpbeh_A*wpbeh_D)/wpbeh_C:
wpbeh_Fc2 := -4/(3*36*wpbeh_C):
wpbeh_F := s ->
  wpbeh_Fc1*wpbeh_H(s) + wpbeh_Fc2:

(* several auxiliary variables *)
eb1  := w -> my_piecewise3(w < wcutoff, 1.455915450052607, 2):
aux1 := s -> wpbeh_D + s^2*wpbeh_H(s):
aux2 := s -> 9*wpbeh_H(s)*s^2/(4*wpbeh_A):
aux3 := (w, s) -> aux1(s) + w^2:
(* aux4 -> 0 only when both s -> 0 and w -> 0 (the omega=0 / PBEh
   default at vanishing gradient).  There term1's t1 (~ +A/2 E1_scaled(aux5),
   aux5 ~ aux4) and t10 (~ -A/2 log(aux4/aux6)) each diverge like
   log(aux4); their sum is finite (the log(aux4) cancels), but evaluated
   separately they are +inf and -inf -> inf-inf = NaN / -inf.  Floor aux4
   (as the sibling gga_x_hjs floors its zeta): the floor passes
   identically through aux5 and aux6, so the cancellation is preserved and
   the finite limit is recovered. *)
aux4 := (w, s) -> m_max(s^2*wpbeh_H(s) + eb1(w)*w^2, xc_reduced_floor):
aux5 := (w, s) -> 9*aux4(w, s)/(4*wpbeh_A):
aux6 := (w, s) -> wpbeh_D + aux4(w, s):

(* and now G(s) *)
(* exp(aux2)*(1 - erf(sqrt(aux2))) = exp(u^2)*erfc(u) = erfcx(u)
   with u = sqrt(aux2); xc_erfcx is the scaled complementary erf,
   so it avoids both the 1 - erf cancellation at large u and the
   exp(u^2) overflow. *)
Ga := s ->
  + sqrt(Pi)*(
    + 15*wpbeh_E
    + 6*wpbeh_C*(1 + wpbeh_F(s)*s^2)*aux1(s)
    + 4*wpbeh_B*aux1(s)^2
    + 8*wpbeh_A*aux1(s)^3)
  / (16*aux1(s)^(7/2))
  - (3*Pi/4)*sqrt(wpbeh_A)*xc_erfcx(sqrt(aux2(s))):
Gb := s ->
  15*sqrt(Pi)*s^2/(16*aux1(s)^(7/2)):

wpbeh_EG_orig := s -> -(3*Pi/4 + Ga(s))/Gb(s):

(* The exact EG is 0/0 as s -> 0: Gb ~ s^2/aux1^(7/2) -> 0 while
   (3*Pi/4 + Ga) -> 0 too (Ga -> -3*Pi/4), so evaluating it directly at
   small s suffers catastrophic cancellation and division by a vanishing
   Gb.  Below EGscut use its small-s Taylor expansion instead -- generated
   here by the Maple pipeline straight from the exact expression rather
   than hard-coded coefficients:
     - to_elementary makes xc_erfcx native so series() can resolve the
       removable s^(-2) singularity;
     - csgn=1 removes the csgn(s^2) that series() emits because it will
       not assume the reduced gradient s >= 0 (sqrt(s^2) = |s|);
     - the parameters are floats, so the limit identity (3*Pi/4+Ga)|_0 = 0
       only holds to ~1e-9 and series() leaves a spurious ~1e-9/s^2
       principal part; keep only the non-negative powers (the true
       expansion is regular at s = 0). *)
wpbeh_EG_poly := proc(s) local P, k;
  P := convert(eval(series(to_elementary(wpbeh_EG_orig(st)), st=0, 24),
    csgn=1), polynom):
  eval(add(coeff(P, st, k)*st^k, k=0..22), st=s)
end proc:
(* Clamp each branch's argument so the exact form is never evaluated
   below EGscut (its 0/0 region) nor the polynomial far above it. *)
wpbeh_EG := s -> my_piecewise3(s > EGscut,
  wpbeh_EG_orig(m_max(s, EGscut)),
  wpbeh_EG_poly(m_min(s, EGscut))
):

term2 := s-> (
  + aux1(s)^2*wpbeh_B
  + aux1(s)*wpbeh_C
  + 2*wpbeh_E
  + aux1(s)*s^2*wpbeh_C*wpbeh_F(s)
  + 2*s^2*wpbeh_EG(s)
)/(2*aux1(s)^3):

term3 := (w, s) -> -w*(
  + 4*aux3(w, s)^2*wpbeh_B
  + 6*aux3(w, s)*wpbeh_C
  + 15*wpbeh_E
  + 6*aux3(w, s)*s^2*wpbeh_C*wpbeh_F(s)
  + 15*s^2*wpbeh_EG(s)
)/(8*aux1(s)*aux3(w, s)^(5/2)):

term4 := (w, s) -> -w^3*(
  + aux3(w, s)*wpbeh_C
  + 5*wpbeh_E
  + aux3(w, s)*s^2*wpbeh_C*wpbeh_F(s)
  + 5*s^2*wpbeh_EG(s)
)/(2*aux1(s)^2*aux3(w, s)^(5/2)):

term5 := (w, s) -> -w^5*(
  + wpbeh_E
  + s^2*wpbeh_EG(s)
)/(aux1(s)^3*aux3(w, s)^(5/2)):

(* --- small-s stabilisation of the rational (aux1-based) terms ---
   For s -> 0, aux1 = D + s^2 H(s) rounds to D in double precision
   (s^2 H ~ 1e-31 is lost against D ~ 0.58), so the (aux1 - D) = s^2 H
   factors generated in the second derivatives of term2..term5 collapse
   to 0/0 -> NaN.  This is the HSE03/HSE06 v2sigma2 / v2rhosigma blow-up
   at small gradient and the long-standing low-sigma crash.

   term2..term5 are rational in s (EG via its polynomial branch, valid
   below EGscut), so the small-s expansion is an exact, convergent
   Taylor series (the nearest pole, aux1 = 0, sits at |s| ~ sqrt(D/Ha1)
   ~ 7.7, so it converges geometrically).  Maple generates it from the
   explicit-EG-polynomial form; term1 carries the erfcx/E1
   transcendentals but stays smooth in s^2 and is left direct. *)
term2345 := (w, s) -> term2(s) + term3(w, s) + term4(w, s) + term5(w, s):

(* series() cannot expand a my_piecewise3, and term2345 carries one
   through wpbeh_EG (plus the m_max/m_min clamps).  Below the cutoff EG
   is its polynomial branch, so collapse my_piecewise3 to that branch and
   the clamps to the identity, leaving a clean rational whose Taylor
   series is exact.  (wpbeh_EG is the only piecewise inside term2345.) *)
term2345_series := (w, s) -> eval(convert(series(
    eval(term2345(w, ss), [my_piecewise3 = ((c, a, b) -> b),
                           m_min = ((a, b) -> a), m_max = ((a, b) -> a)]),
    ss=0, 24), polynom), ss=s):

(* Glue: series below the cutoff, original above it; the m_max/m_min
   clamps keep the unselected branch finite (cf. enforce_smooth_lr).
   The series is an order-24 Taylor polynomial about s = 0; its truncation
   error grows as ~(s/0.7)^23, so it is accurate to machine precision only for
   s below ~0.14 (4e-4 by s = 0.5).  The original is accurate everywhere the
   value is concerned, so the junction belongs as low as the series is still
   exact: 0.13.  With E/Fc1/Fc2 computed exactly (above) EG_poly = EG_orig to
   machine precision, so at 0.13 both branches agree to XC_EPSILON and the hard
   switch is continuous -- no blend needed.  (Above ~0.14 the series has drifted
   away, which was the discontinuity when the cutoff sat at 0.5.) *)
wpbeh_scut := 0.13:
term2345_smooth := (w, s) -> my_piecewise3(s >= wpbeh_scut,
  term2345(w, m_max(s, wpbeh_scut)),
  term2345_series(w, m_min(s, wpbeh_scut))):

(* aux4 - aux6 = -D (since aux6 = D + aux4), so at large w both
   saturate to eb1*w^2 and aux4/aux6 -> 1.  Route through xc_log1p
   with the subtraction written symbolically against the helpers so
   the polynomials stay single-source -- Maple simplifies away the
   matching aux4 terms before codegen, so the emitted C is
   cancellation-free and any future retuning of aux6 flows through
   automatically. *)
t10 := (w, s) ->
  1/2*wpbeh_A*xc_log1p((aux4(w, s) - aux6(w, s))/aux6(w, s)):

(* Use simple gaussian approximation for large w *)
term1_largew := (w, s) ->
  -1/2*wpbeh_A*(-xc_E1_scaled(aux5(w, s))
                + xc_log1p((aux6(w, s) - aux4(w, s))/aux4(w, s))):

(* For everything else use the full blown expression *)
ea1 := -1.128223946706117:
ea2 :=  1.452736265762971:
ea3 := -1.243162299390327:
ea4 :=  0.971824836115601:
ea5 := -0.568861079687373:
ea6 :=  0.246880514820192:
ea7 := -0.065032363850763:
ea8 :=  0.008401793031216:

np1 := w ->
  - 1.5*ea1*sqrt(wpbeh_A)*w
  + 27*ea3*w^3/(8*sqrt(wpbeh_A))
  - 243*ea5*w^5/(32*(wpbeh_A)^(3/2))
  + 2187*ea7*w^7/(128*(wpbeh_A)^(5/2)):

np2 := w ->
  - wpbeh_A
  + 9*ea2*w^2/4.0
  - 81*ea4*w^4/(16*wpbeh_A)
  + 729*ea6*w^6/(64*wpbeh_A^2)
  - 6561*ea8*w^8/(256*wpbeh_A^3):

t1 := (w, s) ->
  1/2*(np1(w)*Pi*xc_erfcx(sqrt(aux5(w, s))) - np2(w)*xc_E1_scaled(aux5(w, s))):

f2 := (w, s) ->
  1/2*ea1*sqrt(Pi)*wpbeh_A/sqrt(aux6(w, s)):
f3 := (w, s) ->
  1/2*ea2*wpbeh_A/aux6(w, s):
f4 := (w, s) ->
  ea3*sqrt(Pi)*(-9/(8*sqrt(aux4(w, s))) + 0.25*wpbeh_A/aux6(w, s)^(3/2)):
f5 := (w, s) ->
  (ea4/128)*(-144/aux4(w, s) + 64*wpbeh_A/aux6(w, s)^2):
f6 := (w, s) ->
  ea5*(3*sqrt(Pi)*(3*aux6(w, s)^(5/2)*(9*aux4(w, s) - 2*wpbeh_A)
    + 4*aux4(w, s)^(3/2)*wpbeh_A^2))/(32*aux6(w, s)^(5/2)*aux4(w, s)^(3/2)*wpbeh_A):
f7 := (w, s) ->
  ea6*((32*wpbeh_A/aux6(w, s)^3 + (-36 + 81*s^2*wpbeh_H(s)/wpbeh_A)/aux4(w, s)^2))/32:
f8 := (w, s) ->
  ea7*(-3*sqrt(Pi)*(-40*aux4(w, s)^(5/2)*wpbeh_A^3
    + 9*aux6(w, s)^(7/2)*(27*aux4(w, s)^2 - 6*aux4(w, s)*wpbeh_A + 4*wpbeh_A^2)))
  /(128*aux6(w, s)^(7/2)*aux4(w, s)^(5/2)*wpbeh_A^2):
f9 := (w, s) -> (
  + 324*ea6*eb1(w)*aux6(w, s)^4*aux4(w, s)*wpbeh_A
  + ea8*(384*aux4(w, s)^3*wpbeh_A^3
    + aux6(w, s)^4*(-729*aux4(w, s)^2 + 324*aux4(w, s)*wpbeh_A - 288*wpbeh_A^2))
  )/(128*aux6(w, s)^4*aux4(w, s)^3*wpbeh_A^2):

t2t9 := (w, s) ->
  + f2(w, s)*w + f3(w, s)*w^2 + f4(w, s)*w^3 + f5(w, s)*w^4
  + f6(w, s)*w^5 + f7(w, s)*w^6 + f8(w, s)*w^7 + f9(w, s)*w^8:

term1 := (w, s) -> my_piecewise3(
  w > wcutoff, term1_largew(w, s),
  t1(m_min(w, wcutoff), s) + t2t9(m_min(w, wcutoff), s) + t10(m_min(w, wcutoff), s)
):

f_wpbeh0 := (w, s) -> - 8/9 *(
  term1(w, s) + term2345_smooth(w, s)
):

f_wpbeh := (rs, z, x) ->
  f_wpbeh0(nu(rs, z), m_max(1e-15, s_scaling_2(gga_s(x)))):

f  := (rs, z, xt, xs0, xs1) ->
  gga_exchange_nsp(f_wpbeh, rs, z, xs0, xs1):
