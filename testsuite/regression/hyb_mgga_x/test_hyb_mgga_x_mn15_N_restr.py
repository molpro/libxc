
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_mn15_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn15", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.263472073732268e+00, 1.061683339733222e+00, 7.882885950783064e-01, 4.291785229358111e-01, -1.912709472565052e-02, -5.309288342530777e-01, -1.021156963852727e+00, -1.327348816500121e+00, -1.324376234425334e+00, -1.257310854614933e+00, -1.158600093383585e+00, -5.401621620645247e-01, -3.020758293177261e-01, -2.639266081254070e-01, -2.510094987374146e-01, -2.112930847526791e-01, -4.717543843797712e-02, 1.862907260145607e-02, 7.021456098180110e-03, 8.500570970323637e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_mn15_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn15", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.018248359209387e+01, 9.695896387057394e+00, 9.006805215865050e+00, 8.039793719711216e+00, 6.704924243917573e+00, 4.921450230508985e+00, 2.705624804608698e+00, 4.173394208924114e-01, -8.997109788487819e-01, -4.791785415835066e-01, -2.055588696016178e-01, -4.091472208403341e-01, -1.896836207699300e-01, -1.597925139344747e-01, -6.901511841897912e-02, -1.267261809226226e-01, -1.015636066235006e-01, 1.573771286330835e-02, 9.061822453469004e-03, 1.130406731675769e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mn15_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn15", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.117894759056171e-05, -4.310419235051360e-05, -4.592124735448801e-05, -5.003240301403046e-05, -5.592237427409373e-05, -6.378755676827290e-05, -7.166661748260464e-05, -6.806663463549592e-05, -1.762859789443462e-05, 1.027126458334181e-06, -1.709108844064383e-03, -9.539005997020318e-03, -1.258780597927975e-02, -2.767440599653940e-02, -1.679219231225935e-01, -1.386959346240208e+00, -3.843108240975044e+00, -2.111552973336470e+00, 1.719961489281439e+00, 3.192009756111622e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mn15_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn15", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.039300452752164e-01, -1.008771966085245e-01, -9.634154426713905e-02, -8.956491115657483e-02, -7.945348131538384e-02, -6.470583298319341e-02, -4.491461398435242e-02, -2.459906284196967e-02, -1.886053725209416e-02, -3.148733102600463e-02, -2.339387703884006e-02, -2.184401112875776e-02, -7.260872466849502e-02, -7.134652216699465e-02, -5.467535762641408e-02, 6.178653351116992e-02, 5.678697003075428e-02, 4.635998697375832e-03, 5.853819012171231e-05, 9.275806213508738e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mn15_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.520291136412639e-02, 8.082757058107636e-02, 8.945427280253457e-02, 1.029554140027093e-01, 1.244840214186549e-01, 1.588199373329625e-01, 2.093756516663663e-01, 2.547134771011017e-01, 1.599953649670703e-01, -2.922413389661107e-01, -5.885306211164212e-01, -4.465482938184401e-03, 9.739615556877399e-01, 3.647053804701680e-01, -2.488914511564826e+00, 2.831003745740079e+01, -4.935211445580287e+01, -4.064906651376490e+02, 8.508432844163508e+03, 9.626102224575785e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mn15_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.843366857182910e-09, -2.482494006293118e-08, -5.328157144912449e-08, -1.125902793502992e-07, -2.514635762477255e-07, -6.260460753244451e-07, -1.810535228354061e-06, -6.085824133972050e-06, -1.948050992901396e-05, 4.321132578230356e-05, 2.439472075529928e-03, 3.106415229128670e-02, 1.321357397905067e-02, 7.432570208361550e-02, 2.973944366459829e+00, -1.348385041246272e+02, -1.017664199244759e+04, -2.604908525185274e+05, 2.270165785426372e+07, 3.293021129735436e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mn15_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.184406309741438e-03, -1.280451378822329e-03, -1.426870041795680e-03, -1.653486616824521e-03, -2.006981808560744e-03, -2.543917645019920e-03, -3.232775038929609e-03, -3.424196629613119e-03, -5.966989769060306e-04, 3.812578258025980e-03, -1.093331804333533e-02, -5.208563850770286e-02, -4.207652139879248e-01, -4.957785969497779e-01, -7.442663735769149e-01, -3.282218382676955e+00, 1.228181897520479e+02, 4.120440937755170e+02, 6.119813359796815e+02, 7.205058978319587e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mn15_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.026317090971482e-13, -2.408308109036203e-13, -3.062983021648870e-13, -4.246360018169738e-13, -6.451765630452075e-13, -9.866734104786533e-13, -1.685232346951083e-13, 2.779301343252506e-11, 6.885730482733586e-10, 2.411471358456500e-08, 2.986212845640444e-06, 4.213900995466551e-04, 1.164618104059322e-03, 2.600865463072866e-02, 4.377224561789734e+00, 1.749893943012089e+03, 9.104945963208500e+05, 6.546300445727824e+08, -8.812052445941225e+12, -9.323593092916081e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mn15_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.860966440277792e-09, 9.095090056983538e-09, 1.118951583306521e-08, 1.499348286007619e-08, 2.256612463950615e-08, 3.952483297680612e-08, 8.286817528723367e-08, 2.023952855417515e-07, 4.011186683385068e-07, -2.424000978455450e-06, -6.232889639989840e-05, -9.398453877699194e-04, 1.003259584296228e-02, 2.412539568312435e-02, -2.234744082248088e+00, -1.946253069948349e+01, 5.654141540747567e+02, 9.712997171885498e+03, 9.953974099732380e+04, 1.231859041324958e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mn15_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.395532306176261e-05, 1.483112244474304e-05, 1.610461032253077e-05, 1.791923229606887e-05, 2.031842534292320e-05, 2.263160036623884e-05, 2.085715780661935e-05, -4.284831310171351e-07, -5.849520131337369e-05, 9.391063967794309e-05, 1.119516522583602e-03, 5.202796823365671e-03, 1.634989793873662e-01, 3.126726383840323e-01, 1.894308294935863e+00, 1.402109689048072e+00, -1.226825250007362e+02, -4.107674341233918e+02, -6.562364845610597e+02, -8.222489657812386e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
