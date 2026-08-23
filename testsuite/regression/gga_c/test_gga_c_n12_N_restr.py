
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_n12_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_n12", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.034302579890575e-01, -1.021714488514151e-01, -1.004383070707356e-01, -9.812246616001732e-02, -9.519065439674911e-02, -9.182525101112433e-02, -8.853718544856709e-02, -8.548603763672084e-02, -7.881688384485853e-02, -5.822399690918693e-02, -4.178442912443204e-02, -5.553445722180626e-02, -5.989357546494370e-02, -4.867230161403260e-02, -3.873914418700389e-02, -1.625452787105766e-02, -7.921252670305523e-02, -7.955998154550861e-02, -2.376920570641183e-02, -3.049301624678308e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_n12_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_n12", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.642407274364083e-01, -1.604810212287187e-01, -1.546780854556816e-01, -1.457312660527954e-01, -1.322787837167619e-01, -1.136118795062151e-01, -9.293891184662456e-02, -8.433097004174935e-02, -1.129075269209011e-01, -1.548274803966430e-01, -1.316040019367165e-01, -6.701455915951400e-02, -9.703450338746537e-02, -5.139773448792660e-02, -7.947877816335983e-02, -7.051707061799991e-04, 8.168381026011724e-02, -7.803979467363291e-02, -3.051728175006489e-02, -4.030556798129708e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_n12_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_n12", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.622653418364543e-07, 5.711619268877201e-07, 5.757512281291482e-07, 5.632866338730550e-07, 5.010792735562441e-07, 3.146458945537657e-07, -1.096470755507753e-07, -5.093972167816081e-07, 3.350845349377422e-06, 3.643844310460285e-05, 2.264312034597972e-04, 3.896466944511991e-04, 1.105639604597822e-02, -1.320462962472802e-03, 3.320735154150330e-02, -9.729419707637331e-02, -1.197064368352252e+01, -4.839702894941222e+01, -7.973925050727517e+01, -9.969800401895917e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_n12_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_n12", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.159333650102365e-03, -1.342346237850723e-03, -1.608928389494976e-03, -1.986933418408876e-03, -2.476589048847539e-03, -2.919263743465949e-03, -2.503992278767842e-03, 1.784620644539297e-03, 1.696156597400771e-02, 1.516150402369934e-02, -1.247693407321232e-01, -2.272214434726596e-01, 1.006992480213175e-02, -2.644192971121886e-01, 2.159204034980738e+00, -4.159271427949425e+01, 2.612788087711354e+02, 1.840389281805282e+03, -2.705118400722837e+04, -3.340086608201509e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_n12_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_n12", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.166561437874833e-08, 1.448355919504339e-08, 1.914418229082670e-08, 2.712088186373256e-08, 4.099832455819091e-08, 6.335701566090270e-08, 7.869484077454561e-08, -1.135226233774253e-07, -2.215343460178269e-06, -7.135845860131455e-06, 3.087696933470047e-04, 1.726092398368334e-02, -1.414368679356610e-02, 8.763015318724503e-02, -2.184779564408071e+00, 2.227364282878442e+02, -1.647436149819905e+04, -5.440136714244827e+06, -1.103602846920923e+09, -1.030608394268820e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_n12_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_n12", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.785110319303697e-13, -2.268915160888336e-13, -3.135487581574282e-13, -4.802799762017844e-13, -8.254775072809843e-13, -1.554177912128298e-12, -2.509136617797740e-12, 7.788415669314638e-12, 2.396159496931201e-10, -1.030004405369583e-09, -1.407500527863755e-06, -1.463339148476375e-03, -1.013346453274147e-02, -2.906738386195072e-02, 1.344048413468484e+00, -1.125352736366586e+03, 2.327776348536234e+06, 1.704349267515463e+10, 4.043275629040629e+14, 2.911858015258379e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
