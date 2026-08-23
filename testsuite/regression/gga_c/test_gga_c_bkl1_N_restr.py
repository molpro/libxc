
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_bkl1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bkl1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.907737565955865e-02, -1.833127078457359e-02, -1.729038864962612e-02, -1.586033361083864e-02, -1.394274051359794e-02, -1.147208164893406e-02, -8.499240143949115e-03, -5.329389314411295e-03, -2.601798432693769e-03, -9.784208464317012e-04, -6.201888155057658e-04, -1.116617136521812e-02, -2.497592649096191e-02, -8.350175229902453e-03, -1.902519271686351e-03, -2.358182331424010e-04, -1.073158710673052e-05, -1.071956141075414e-07, -1.065881045596282e-10, -3.416556730011660e-15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_bkl1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bkl1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.126409180288401e-02, -6.937927017583539e-02, -6.666899077713447e-02, -6.278256364269656e-02, -5.725001379638719e-02, -4.951441947347190e-02, -3.915087696018573e-02, -2.655052506729298e-02, -1.406014784549679e-02, -5.639079594736341e-03, -3.638688636134836e-03, -4.637729945461826e-02, -7.409983919041355e-02, -3.679136984318236e-02, -1.036057102822884e-02, -1.420314256820080e-03, -6.756964775384141e-05, -6.898926410717173e-07, -6.967504885420162e-10, -2.260149147332259e-14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_bkl1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bkl1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.613296548143543e-07, 5.849604213063431e-07, 6.197450130711874e-07, 6.712115630604827e-07, 7.475003576393496e-07, 8.595640957172458e-07, 1.018233824111576e-06, 1.222829505431253e-06, 1.454565845699472e-06, 1.888960822114854e-06, 8.103767223520448e-06, 2.831558355791650e-03, 1.800155949979182e-02, 1.058760508996981e-02, 8.008912597087600e-03, 6.359489016704674e-03, 3.830193840574671e-03, 1.286139604388795e-03, 1.547615528690690e-04, 3.852685125835042e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_bkl1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bkl1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.194434096394663e-04, -7.675040827851257e-04, -8.405554292639131e-04, -9.536609216164605e-04, -1.132312676398045e-03, -1.418586463881104e-03, -1.872853571216128e-03, -2.542316498292403e-03, -3.359607227397595e-03, -4.332437781772374e-03, -1.060247332685528e-02, -1.704112201081907e-01, -1.631406861976033e-01, -4.475298241320846e-01, -6.277674122746788e-01, -5.969535121200601e-01, -3.622230902974553e-01, -1.163657970590334e-01, -1.350037977742580e-02, -3.286557169661233e-04]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_bkl1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bkl1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.713280359919090e-09, 8.767675737284053e-09, 1.051944358902599e-08, 1.360668018398449e-08, 1.950071023919922e-08, 3.199505245182752e-08, 6.213098217569932e-08, 1.463592992508490e-07, 4.262251386820658e-07, 1.755263426386709e-06, 2.845516778184398e-05, 1.360639563858648e-02, 5.676131443997518e-02, 1.655801575022597e-01, 5.936976891927989e-01, 3.205137638713938e+00, 2.442320281580113e+01, 2.570052866594838e+02, 3.541872488159327e+03, 6.601379928980117e+04]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_bkl1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bkl1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.386684177278457e-13, -1.662109024931857e-13, -2.153237625056281e-13, -3.112879926734851e-13, -5.244424353045642e-13, -1.089441659499953e-12, -2.988995598385756e-12, -1.170467212848381e-11, -7.226350813964391e-11, -9.252084178182680e-10, -9.865711387171878e-08, -1.696323380624394e-03, -4.689959343660029e-02, -9.187356862158041e-02, -7.484179228127656e-01, -2.206737239010677e+01, -2.087816695121035e+03, -7.191746194489909e+05, -1.180119515305054e+09, -1.687923049181933e+13]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
