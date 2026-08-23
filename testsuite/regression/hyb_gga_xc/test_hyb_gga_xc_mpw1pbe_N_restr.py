
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_mpw1pbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1pbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.307592042165386e+00, -3.245255676391628e+00, -3.157940130558671e+00, -3.037055793144268e+00, -2.872483462661983e+00, -2.653767228273855e+00, -2.372936272062734e+00, -2.029582542752628e+00, -1.637603833076101e+00, -1.227812436425979e+00, -8.272051473907660e-01, -5.443589039931341e-01, -4.763011436444295e-01, -3.929438928426208e-01, -2.825355537798446e-01, -1.789382607223879e-01, -1.020692450411886e-01, -2.674040124594036e-02, -5.150293765246856e-04, -1.264221486802535e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_mpw1pbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.165685961549825e+00, -4.079481030107115e+00, -3.958620399381993e+00, -3.791064435978205e+00, -3.562485820029602e+00, -3.257778385314170e+00, -2.864800851492961e+00, -2.381590625445075e+00, -1.828336636634871e+00, -1.266874581434525e+00, -8.260063318898930e-01, -6.897550679738673e-01, -6.185737255750210e-01, -4.972597506837655e-01, -3.341151781165847e-01, -1.760567935191791e-01, -9.470198791641485e-02, -6.863408897400150e-02, -1.896519175506470e-03, -4.604591251021332e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw1pbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.405226213611774e-06, -2.600960463015166e-06, -2.909476219518948e-06, -3.415362878918500e-06, -4.292880935556103e-06, -5.941226749518553e-06, -9.404303163183361e-06, -1.790491929367101e-05, -4.369634584863780e-05, -1.468722394634465e-04, -7.272542592742970e-04, -1.941598822134539e-03, -1.374619549142744e-03, -6.248621817491591e-03, -3.481900098008058e-02, -3.260988611784413e-01, -2.798527670650858e+00, 7.431906622033539e+01, 3.293926611817450e+02, 6.171706726111551e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw1pbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.248037902026530e-03, -9.670480177923950e-03, -1.031173171886533e-02, -1.130819959703819e-02, -1.290936117212713e-02, -1.560756655497666e-02, -2.046921177588554e-02, -3.006710554123112e-02, -5.125558860462159e-02, -1.020030085122716e-01, -2.453620008780626e-01, -4.304474367797101e-01, -4.933335172022911e-01, -9.072728693540129e-01, -2.638280638762690e+00, -8.810850944588745e+00, 6.444000943733077e+01, -1.142385483188091e+03, -1.774508915117850e+04, -3.157037324840642e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw1pbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.839566032349466e-08, 2.092089857892138e-08, 2.515471796569954e-08, 3.274023298276390e-08, 4.767797169000408e-08, 8.130748413594553e-08, 1.726641715191498e-07, 4.941521501170286e-07, 2.081700102485553e-06, 1.354886710355506e-05, 2.228472486946373e-04, 7.484030948406936e-03, 1.264464237223356e-02, 8.025761837853861e-02, 1.138706230052787e+00, 2.347970694095117e+01, -6.503394876597629e+03, 9.728805220399461e+05, 4.228782403966155e+09, 5.834518235295813e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw1pbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.707770457282382e-14, -1.816541603393029e-14, -1.902264659297121e-14, -1.739022543349769e-14, -1.721973394521490e-15, 9.634774105131901e-14, 8.086909386777287e-13, 8.403802014031192e-12, 1.588693924130580e-10, 7.524340177040696e-09, 9.624466607437582e-07, -3.476952399897115e-04, -3.929544178558631e-03, -1.987874593576594e-02, -5.443798986713237e-01, 6.096772835794067e+01, 6.960122481805389e+05, -9.130774771090008e+09, -1.570023295355499e+15, -1.684275538389484e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
