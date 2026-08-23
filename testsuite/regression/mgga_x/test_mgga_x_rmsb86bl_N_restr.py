
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_rmsb86bl_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsb86bl", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.569131171003733e+00, -4.479452697636049e+00, -4.353845431258419e+00, -4.179963026528752e+00, -3.943273828440336e+00, -3.628801186234238e+00, -3.225254384925617e+00, -2.732532733422595e+00, -2.171404916209044e+00, -1.570634058142396e+00, -9.938054898011656e-01, -6.190178864035423e-01, -5.590673681877815e-01, -4.763917401000640e-01, -3.395374245163018e-01, -2.139119829992323e-01, -1.248918834909332e-01, -5.671623335868285e-02, -1.808589606684935e-02, -4.037658736420963e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_rmsb86bl_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsb86bl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.911115918345518e+00, -5.788330689169012e+00, -5.616152421197323e+00, -5.377371581616883e+00, -5.051411296431128e+00, -4.616256250963875e+00, -4.053005802480484e+00, -3.352799506166880e+00, -2.514574637234543e+00, -1.485288973626044e+00, -9.914463850676808e-01, -8.133264270181675e-01, -7.534899139024087e-01, -6.005302532306737e-01, -3.535883795541568e-01, -1.875445003006499e-01, -9.720368479879908e-02, -5.445298322835631e-02, -1.699776835638335e-02, -3.516723827717526e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmsb86bl_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsb86bl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.962026795759125e-06, -2.128889965913632e-06, -2.394087086719373e-06, -2.834618847993368e-06, -3.615079644152053e-06, -5.135613137899979e-06, -8.559218895005195e-06, -1.833691467711930e-05, -6.227630926934856e-05, -4.836587891417510e-04, -1.345526746569707e-03, -5.657565845065621e-03, -1.260630213721261e-02, -5.129950677046742e-02, -2.099998300188640e-01, -6.033798718518808e-01, -5.630936703040843e+00, -4.781647413311899e+01, -1.937722103144518e+03, -3.947120946617588e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmsb86bl_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsb86bl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.390195800712812e-05, 4.862654793584639e-05, 5.636666526394825e-05, 6.980275474400906e-05, 9.517201066229588e-05, 1.493035427888146e-04, 2.872872884942654e-04, 7.421119515744099e-04, 2.891468484447317e-03, 1.552877576528047e-02, 5.393284929845095e-03, 5.094297083474654e-03, 1.672631135437525e-02, 6.044636020779246e-02, 7.677660396741302e-02, 1.024349817155073e-02, 1.059541673807069e-02, 4.465389650998927e-05, 2.179196783699112e-07, 4.289088115335675e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmsb86bl_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsb86bl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.150671385427641e-02, -1.196547465664437e-02, -1.265050941429425e-02, -1.368726353226576e-02, -1.528007218640631e-02, -1.775004213004764e-02, -2.147173098863974e-02, -2.582300735226597e-02, -2.188897626335781e-02, -1.447688850449663e-01, -4.182594937096898e-01, -8.334651621282133e-01, -1.283840514661921e+00, -1.612724737740655e+00, -4.885725431866280e+00, -3.236520547821506e+01, -5.462275953761314e+01, 1.338904344285615e+02, 5.401613599726951e+02, 8.321235445792472e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmsb86bl_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsb86bl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.446220264308951e-09, -1.074705524309716e-08, -1.503840226767083e-08, -2.395475416442280e-08, -4.549731159837286e-08, -1.097109183089096e-07, -3.658991445605384e-07, -1.892503594086326e-06, -1.717413069798404e-05, -7.931913424447722e-05, 2.964059118823651e-04, 5.471855955584554e-03, -6.578330439969313e-02, 2.735078151257490e-01, 3.782707371310846e+00, 5.153754117253709e+02, 1.584570838263173e+04, -1.427802576579082e+06, -5.530295015077034e+09, -8.175262161552905e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmsb86bl_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsb86bl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.152521260799622e-05, 3.549335527835689e-05, 4.207571354934809e-05, 5.369602482332018e-05, 7.612613681119772e-05, 1.253216441970740e-04, 2.547398634128646e-04, 6.941106863046237e-04, 2.764856402310546e-03, 6.753049432753105e-03, 3.183601260956173e-03, 2.853447258958655e-02, 3.385412526293418e-01, -3.544639665315356e-02, -5.509526048739802e-01, -4.726249207755004e+01, -1.634964575999252e+02, -5.599271153282344e+01, -6.315933761913314e+01, -1.878045595330341e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmsb86bl_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsb86bl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.498651004480302e-13, 8.291413132702673e-13, 1.176558559658014e-12, 1.944420372292542e-12, 3.996528683947092e-12, 1.121467906351806e-11, 4.901195060165189e-11, 4.013140727173814e-10, 7.883743148576313e-09, 2.191572030068406e-07, -1.246205064055484e-06, 1.357426926097334e-05, -1.794594297251938e-02, 2.794329361960901e-02, -4.567645604416173e+00, -9.827125088878787e+03, -3.982709345925247e+06, 6.691100836458289e+09, 3.955099048082088e+15, 4.608486382392233e+23]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmsb86bl_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsb86bl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.156346659686188e-10, -1.098846350729428e-09, -1.427966014580179e-09, -2.079865779989074e-09, -3.566294496379903e-09, -7.718250037512108e-09, -2.326091286274579e-08, -1.120236828698266e-07, -1.033138768440705e-06, -9.319425131420512e-06, 4.049713413710700e-05, 5.696681495170901e-04, 6.171626989610752e-02, -1.664926180375230e-02, 3.253752695564518e+00, 9.479276609481050e+02, 3.896314509297349e+04, 3.830533955141483e+05, 4.765826708872438e+07, 1.075651701497439e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmsb86bl_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsb86bl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.311453361287016e-06, 1.480367026998211e-06, 1.761710992019837e-06, 2.261387082175935e-06, 3.234571254159945e-06, 5.398411682308398e-06, 1.121690929367520e-05, 3.175861594996834e-05, 1.373721213131333e-04, 4.066125190215805e-04, -6.132677342696588e-04, -3.343277151691891e-03, -2.063838618154588e-01, -8.225706884835364e-03, -2.037717927072626e+00, -8.876064359922744e+01, -3.197692935230061e+02, -9.979695617715383e+01, -1.078065528030161e+02, -3.298919256709272e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
