
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_tm_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tm", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.756180712327265e-02, -3.716222560801494e-02, -3.658381279105397e-02, -3.574385252088627e-02, -3.451803065074029e-02, -3.271554115333869e-02, -3.003684463306991e-02, -2.601716813443497e-02, -2.010569931774822e-02, -1.288900928905737e-02, -1.058882620727294e-02, -4.276265422774446e-02, -5.156625873960394e-02, -3.219280554288223e-02, -1.633202949003651e-02, -4.579505279970367e-03, -3.285742354112807e-04, -3.649454157247715e-06, -3.554214054967476e-09, -1.089368619641544e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_tm_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.117021547780606e-01, -1.105500631859754e-01, -1.089015653653236e-01, -1.065491037860330e-01, -1.032064321045247e-01, -9.848955897873826e-02, -9.190322594510994e-02, -8.280046307879280e-02, -7.004563741466900e-02, -5.229857307506141e-02, -4.511361545299896e-02, -8.848842536406681e-02, -8.274637458296899e-02, -7.515408986507696e-02, -5.357731784761866e-02, -2.194090782566870e-02, -2.013883307969692e-03, -2.425499483136605e-05, -2.445870534977077e-08, -7.701796337849961e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tm_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.647390365057084e-06, 1.726570541459561e-06, 1.846538069890275e-06, 2.032296587510074e-06, 2.328777635913441e-06, 2.822272941201764e-06, 3.693031069204187e-06, 5.363323002411917e-06, 9.008890764985953e-06, 1.920415699849001e-05, 9.858771662393753e-05, 3.547962432015559e-03, 1.106339649969627e-02, 2.090016383246777e-02, 4.397705856900657e-02, 1.036888204758224e-01, 1.216534104707280e-01, 4.895767794297418e-02, 6.036931068356017e-03, 1.504923920425260e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tm_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.955971326734232e-03, -1.916687614369313e-03, -1.860270184130075e-03, -1.779256459548492e-03, -1.662972669359848e-03, -1.496481068399044e-03, -1.260695487428452e-03, -9.395221568114519e-04, -5.520461325405134e-04, -2.158439386636698e-04, -7.498203832850223e-05, -8.428708640476290e-05, -1.288233134609593e-03, -9.032265966874462e-03, -6.307588467192204e-03, -1.440556443896560e-03, -9.488360231868679e-05, -1.351545213157031e-06, -1.940012106141267e-09, -8.391934123832062e-14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tm_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.999644633178039e-04, -7.423376131943591e-04, -8.075209198996501e-04, -9.107121389057105e-04, -1.080848438013161e-03, -1.378025912007989e-03, -1.942735372782964e-03, -3.171070857921018e-03, -6.563936181248143e-03, -1.887409052566835e-02, -6.714237747851741e-02, -2.643925242868382e-02, 6.065142030446745e-03, -1.455059840608554e-01, -9.681002651577666e-01, -5.632638430914874e+00, -9.968244360968141e+00, -4.168604402668149e+00, -4.930538918089372e-01, -1.178921142687758e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tm_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.283362624273569e-08, 1.447497377922021e-08, 1.720502399131703e-08, 2.204153526110719e-08, 3.141636515741815e-08, 5.206330266616175e-08, 1.065207861296711e-07, 2.919667396017050e-07, 1.212472015770727e-06, 9.324144367427226e-06, 1.914955970886044e-04, 1.116205728805942e-03, -1.174422000060220e-02, 6.545222773814792e-02, 1.182415475122890e+00, 3.328766103609255e+01, 7.054086417753900e+02, 9.676868747700897e+03, 1.380813747235766e+05, 2.578588416989904e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_tm_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.254818174397416e-05, -1.327313914243381e-05, -1.438741609945908e-05, -1.614772044765541e-05, -1.903432970914076e-05, -2.400194898303993e-05, -3.303238494437956e-05, -5.005977837430651e-05, -7.990477194100695e-05, -1.144385768893107e-04, -1.543760794905758e-04, -9.561411625632286e-05, 3.425228928894649e-04, -3.872564916792639e-02, -2.155587896865837e-01, -4.495791089474959e-01, -4.029172607117971e-01, -1.837076662960797e-01, -3.053424972683925e-02, -9.987973801430002e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tm_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.981410189844515e-13, -2.376962071698246e-13, -3.088456078901005e-13, -4.500753985654037e-13, -7.732117272796457e-13, -1.680584196130687e-12, -5.101733724400358e-12, -2.479659417764432e-11, -2.334110812467888e-10, -5.672779804703127e-09, -7.692735494153563e-07, -7.506175881822034e-04, -5.186862927430156e-03, -4.571345449080710e-02, -1.824372440548762e+00, -2.520161823907773e+02, -6.134589378671693e+04, -2.712590785627696e+07, -4.601120040028593e+10, -6.593263121608995e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_tm_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.311497990670058e-10, -2.569087434680257e-10, -2.986660019248081e-10, -3.697860595357343e-10, -4.993662684630149e-10, -7.573403763731710e-10, -1.329276694042692e-09, -2.740439048361101e-09, -6.405642041586341e-09, -1.653563184757805e-08, -1.381750367436188e-07, -4.124318416481379e-05, -5.428147688724446e-03, -5.492299957786240e-02, -1.781281480144036e-01, -4.644877929818076e-01, -1.155101909389712e+00, -2.606835432546815e+00, -3.045046212980309e+00, -1.211787285817963e+00]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_tm_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.006093048806687e-06, 1.055669817274645e-06, 1.130424258305318e-06, 1.245142656258249e-06, 1.425054098488173e-06, 1.713799422732017e-06, 2.183668367459917e-06, 2.926179968461943e-06, 3.913721298943548e-06, 4.731408292761394e-06, 7.500729650713540e-06, 6.055837315687117e-05, 6.414053118924226e-03, 1.242101315201281e-01, 2.887670771629762e-01, 4.226008820168219e-01, 3.725121507333373e-01, 1.830662933415132e-01, 3.265029081978978e-02, 1.115860166226147e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
