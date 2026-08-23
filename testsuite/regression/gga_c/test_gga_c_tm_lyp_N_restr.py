
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_tm_lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tm_lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.739046903104745e-02, -5.722877907329280e-02, -5.698734069770712e-02, -5.662073365580033e-02, -5.605029827207073e-02, -5.513038849273295e-02, -5.356726685890100e-02, -5.070466406305551e-02, -4.493373655615863e-02, -3.277971323612305e-02, -2.107218029139862e-02, -4.123573002544344e-02, -4.210388764892467e-02, -3.533845227682317e-02, -2.187523423594223e-02, -1.568156876255766e-03, -6.218847308169023e-04, -6.850279744974696e-03, -1.652855944281680e-03, -1.898557823798151e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_tm_lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tm_lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.477151591078513e-02, -6.489331528365581e-02, -6.507880891368460e-02, -6.536840535579284e-02, -6.583681491128454e-02, -6.663332928103083e-02, -6.808539116914898e-02, -7.098967318301463e-02, -7.744796517765619e-02, -9.204165385997785e-02, -1.012544243490115e-01, -5.780629815566257e-02, -5.180850405565331e-02, -5.478566234726226e-02, -5.965432055999920e-02, -5.989655719714761e-02, -2.487091627409227e-02, -8.700366143141822e-03, -2.180636316102907e-03, -2.528353161323485e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_tm_lyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tm_lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.734063842318093e-08, 7.470805245418240e-08, 8.672913670363429e-08, 1.074581914415043e-07, 1.461625190444471e-07, 2.271934136062884e-07, 4.272108386179745e-07, 1.052677097617019e-06, 3.788948562396132e-06, 2.247461783198738e-05, 2.029028358858479e-04, 9.927966991120723e-04, 1.942109871079054e-03, 5.566340126296583e-03, 3.299499234131558e-02, 3.486459373334041e-01, 2.746618084233880e+00, 1.539246810841907e-01, 1.588704210933313e-19, 3.112488789850751e-232]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_tm_lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tm_lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.611893422816208e-05, 6.225236511068500e-05, 7.224855925499369e-05, 8.945715475326932e-05, 1.215093157004800e-04, 1.883640898509243e-04, 3.523934657301485e-04, 8.593363088244578e-04, 3.008305286503184e-03, 1.595110437706425e-02, 7.786265244432901e-02, 2.653429616375411e-02, 1.057358132016017e-02, 8.513194522088378e-02, 6.157446356026446e-01, 4.549846077808910e+00, -3.409046208921481e+00, -6.933662988872959e+01, -2.412010805107387e+03, -2.169755874461980e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_tm_lyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tm_lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.376333059936473e-10, -7.522068731104989e-10, -9.538062298761469e-10, -1.341416011522852e-09, -2.188279011006978e-09, -4.413301315889171e-09, -1.204311763019208e-08, -5.046170051734328e-08, -3.853625412664341e-07, -6.485369045209014e-06, -2.122428686992190e-04, -2.641550147707295e-03, -7.687743722362197e-03, -4.132370682577317e-02, -7.267707746850860e-01, -3.563872303435539e+01, -1.044526966584742e+03, 1.242305764174227e+04, 1.061232822170494e-11, 1.499657772657238e-220]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_tm_lyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tm_lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
