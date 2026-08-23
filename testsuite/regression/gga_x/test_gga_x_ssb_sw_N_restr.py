
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_ssb_sw_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb_sw", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.390960010535697e+00, -4.303434401187639e+00, -4.180935135358226e+00, -4.011579459297147e+00, -3.781620248048448e+00, -3.477595317139669e+00, -3.091534870882978e+00, -2.630490293338214e+00, -2.124358539416669e+00, -1.606520525022159e+00, -1.082256397087944e+00, -6.687650941978103e-01, -5.784124896492377e-01, -4.724634918232340e-01, -3.478534549887636e-01, -2.287510674656591e-01, -1.206789237340375e-01, -4.186767429237061e-02, -8.769340895742389e-03, -9.701609613061313e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_ssb_sw_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb_sw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.776500508044401e+00, -5.653487450489323e+00, -5.480248229953966e+00, -5.238366430128546e+00, -4.904576137001224e+00, -4.451256539079036e+00, -3.850403679949773e+00, -3.094670243552807e+00, -2.270300992280287e+00, -1.569001986238571e+00, -1.032321139723457e+00, -8.497762040438185e-01, -7.666496996082304e-01, -5.815069202383266e-01, -3.532841105851763e-01, -2.162998538612561e-01, -1.359825239697161e-01, -5.449278317593750e-02, -1.167908288960571e-02, -1.293528924625889e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ssb_sw_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb_sw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.381357659978144e-07, -9.649409912129646e-07, -1.180702966317756e-06, -1.574629789741869e-06, -2.366903956776057e-06, -4.176470452888417e-06, -8.984639910059331e-06, -2.365664403101629e-05, -7.093216737287038e-05, -2.305891866454210e-04, -1.093844905440566e-03, -3.363037760938327e-03, -1.696675873164210e-03, -1.799830170935238e-02, -1.041391475419894e-01, -4.749772755343027e-01, -1.689492019010307e+00, -2.998760626839818e+00, -3.640658717961424e+00, -4.022292191546383e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ssb_sw_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb_sw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.311000456739942e-02, -1.388967854076090e-02, -1.511735894371677e-02, -1.712885560875586e-02, -2.060906198951694e-02, -2.704052271420999e-02, -3.949210617657942e-02, -6.131990000118120e-02, -8.084338629961267e-02, -7.000853854794566e-02, -7.908839659953412e-02, -7.659371225474294e-01, -6.792421901654001e-01, -1.761519254671287e+00, -2.284151992046824e+00, 2.770738417172610e+00, 2.774974760198075e+01, -4.051850958044587e+02, -1.344334594174141e+04, -1.116609266769516e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ssb_sw_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb_sw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.530331970049217e-08, 3.088865337843815e-08, 4.100371599363098e-08, 6.113378774379892e-08, 1.065999299568326e-07, 2.269590587120851e-07, 6.028612843875276e-07, 1.851242755807771e-06, 4.503744846736012e-06, -7.531009251163910e-06, -3.598278247490930e-04, 2.476111359044837e-02, 2.144731678455679e-02, 3.172869141748447e-01, 4.960798730551902e-01, -4.800139481329563e+01, -5.010018823173782e+03, -3.587003232774420e+05, -5.089624657005806e+07, -4.167222502601510e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ssb_sw_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb_sw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.045449513965977e-13, -2.657477431422156e-13, -3.854942289196591e-13, -6.516703748262866e-13, -1.355249449839112e-12, -3.676233218079373e-12, -1.337490909363714e-11, -5.524425478243782e-11, 1.436705304707228e-10, 2.401891185286178e-08, 3.376281707135704e-06, -1.405938943158682e-03, -5.923911417267097e-03, -7.613787734367777e-02, 1.485370510592753e+00, 5.483450534308977e+02, 4.951226567883195e+05, 1.088225480313116e+09, 1.848471923914256e+13, 1.174801930539784e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
