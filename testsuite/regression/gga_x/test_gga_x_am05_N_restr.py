
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_am05_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_am05", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.167280710518082e+00, -4.083491583766089e+00, -3.966108051152889e+00, -3.803561425831923e+00, -3.582213627644880e+00, -3.287982034813992e+00, -2.910270265568263e+00, -2.449393731805581e+00, -1.927756939133333e+00, -1.398824388360517e+00, -9.256671478754911e-01, -6.316001611979660e-01, -5.494596220278671e-01, -4.438468049217552e-01, -3.093877761185277e-01, -1.910381248016876e-01, -1.120345195843248e-01, -6.539196236194111e-02, -3.896022980713758e-02, -2.401385446610702e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_am05_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_am05", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.530182668622640e+00, -5.416766976201157e+00, -5.257663097344176e+00, -5.036876537584502e+00, -4.735188015330507e+00, -4.331845727068870e+00, -3.808837042675111e+00, -3.159255361932301e+00, -2.403241486610304e+00, -1.624437124623590e+00, -1.027871729265584e+00, -8.306321558979329e-01, -7.309288820469061e-01, -5.792105422326431e-01, -3.740527990446790e-01, -1.888525569259920e-01, -8.055954942154771e-02, -3.318991423134497e-02, -1.347261054927750e-02, -5.552591578310157e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_am05_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_am05", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.810309678908256e-07, -3.187527371674469e-07, -3.815141371558328e-07, -4.925961558902940e-07, -7.070014865192920e-07, -1.173461270243329e-06, -2.365647695433417e-06, -6.111394817312835e-06, -2.108382563603507e-05, -9.684399772055527e-05, -5.496057169651537e-04, -9.229079923031621e-04, -6.256058765132850e-04, -4.675714310814929e-03, -3.624334732062157e-02, -3.526921935120847e-01, -4.665244294432780e+00, -1.216811730234177e+02, -1.047530772366083e+04, -5.595811866644363e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_am05_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_am05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.093639361794744e-02, -1.143940138998356e-02, -1.220774117765233e-02, -1.341359304862834e-02, -1.538264366867196e-02, -1.879027335244642e-02, -2.520440094400350e-02, -3.874359140098212e-02, -7.122022128685324e-02, -1.545402135151557e-01, -3.663393167282407e-01, -5.165425724872907e-01, -6.119483122854202e-01, -1.104519109279034e+00, -2.973974153866414e+00, -8.689260131143277e+00, -1.698767663105883e+01, 1.201160501671992e+02, 1.707005827178173e+04, 8.076190243776429e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_am05_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_am05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.900191325848904e-09, 8.236955564554037e-09, 1.060534590486254e-08, 1.519128271909995e-08, 2.525140687114989e-08, 5.148504681100283e-08, 1.378855236481210e-07, 5.222449603150102e-07, 2.955979308082596e-06, 2.522365745094777e-05, 4.077091519735337e-04, 5.575700734658367e-03, 7.205233988931958e-03, 7.452645480244696e-02, 1.048709249776122e+00, 1.757278531649165e+01, -7.020492734570020e+02, -1.045243930619085e+06, -8.928597087500328e+09, -2.721206530802590e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_am05_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_am05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.158745691289505e-14, -6.530797027111882e-14, -9.146958534809938e-14, -1.477654844022425e-13, -2.914418406346546e-13, -7.564052392998000e-13, -2.832072551664088e-12, -1.679410065182432e-11, -1.613554711893555e-10, -1.335359519229361e-09, 1.289680516662826e-07, -2.879777742082686e-04, -1.923149534242606e-03, -1.684440002768254e-02, -3.085260365871009e-01, 1.222111934743105e+02, 4.769703295565195e+05, 1.371437389202578e+10, 1.574526011248684e+16, 4.661388391040256e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
