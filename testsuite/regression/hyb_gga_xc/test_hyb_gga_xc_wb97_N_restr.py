
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_wb97_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.166094576903291e+00, -4.082894864801005e+00, -3.966431235285335e+00, -3.805359305199991e+00, -3.586440272193234e+00, -3.296269427543727e+00, -2.925186646837968e+00, -2.473931484858652e+00, -1.962641057599304e+00, -1.440250192429982e+00, -9.078819791370379e-01, -4.952344418192521e-01, -4.099189894539341e-01, -3.072332848169054e-01, -1.824521202164688e-01, -5.710343019821305e-02, 1.079630678468182e-02, 9.285967762002995e-03, 2.328457802977483e-03, 2.716651820252372e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_wb97_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.307387473931667e+00, -5.189558876977938e+00, -5.024137060755940e+00, -4.794474800006499e+00, -4.480885647123451e+00, -4.063317433043959e+00, -3.527947463870333e+00, -2.877105333264059e+00, -2.125076793832836e+00, -1.265283249863550e+00, -6.923500910917270e-01, -6.586579280290500e-01, -6.105500830798306e-01, -4.092904904370462e-01, -2.491887037150916e-01, -1.121445346964428e-01, 1.332989362815875e-02, 1.349444603201347e-02, 3.083628547749528e-03, 3.619638728913720e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.271323578976800e-06, -3.567782864282102e-06, -4.040424629988397e-06, -4.826330098495176e-06, -6.210196482561582e-06, -8.840499093883345e-06, -1.437189229241437e-05, -2.781010262432568e-05, -7.044219761746329e-05, -2.938593435602962e-04, -1.589851720700897e-03, -4.304753637519687e-03, 6.688560991326468e-03, -1.715970426224864e-02, -3.177505491424453e-02, 1.875243370984892e-02, -8.822458863087277e-01, -5.411163235880892e+00, -9.533315508650007e+00, -1.201265848680128e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.335017189132953e-02, -1.401818214864853e-02, -1.502004144216897e-02, -1.654439893563686e-02, -1.890533683005984e-02, -2.264929637439066e-02, -2.888911847345882e-02, -4.144764967296670e-02, -8.657741247174215e-02, -3.546248829188510e-01, -1.050674986614777e+00, -7.323024792530505e-01, -8.206525189886960e-01, -1.308804493646064e+00, -5.401816934073281e-01, -1.862096899287046e+01, -4.610973506953395e+01, 3.180005335444177e+02, 3.755864121280734e+03, 3.113070725795760e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.523389033835532e-08, 4.049288468695049e-08, 4.917144869147720e-08, 6.426045000420981e-08, 9.234579465171388e-08, 1.495095710329959e-07, 2.835177439270668e-07, 7.470637042739477e-07, 5.296913943986967e-06, 1.135803430535281e-04, 2.436999984966591e-03, 2.415508180026476e-02, 8.594924054729787e-02, 1.696941170529025e-01, -1.037488249949743e+00, 8.587557827484321e+01, 2.444888790979085e+03, -5.623565666341940e+05, -1.315183802034130e+08, -1.241582556906862e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.315567227411479e-13, -1.574165783974090e-13, -2.000643135573678e-13, -2.711354637567807e-13, -3.787260962027866e-13, -4.177527257305979e-13, 9.073199936872636e-13, 1.577202861259549e-11, 1.174175199929012e-11, -2.096658223753570e-08, -3.405399592213783e-06, -1.296014471216988e-03, -4.429730716978784e-02, -2.848863519706379e-02, 1.247713972334414e+00, -6.144428582249964e+02, -1.328197366215306e+05, 1.789680205180173e+09, 4.822292605056092e+13, 3.508404109208123e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
