
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_mcweeny_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_mcweeny", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.828347094405314e-02, -9.817949637044153e-02, -9.802675136233967e-02, -9.780032284159978e-02, -9.746033931479348e-02, -9.694054939151797e-02, -9.612552109903687e-02, -9.480206389357021e-02, -9.254627519227958e-02, -8.837084662809234e-02, -7.809638209241261e-02, -5.475426924436563e-02, -5.005090117703626e-02, -4.800337916044180e-02, -3.926204295229605e-02, -2.515543161594208e-02, -1.055910684494043e-02, -2.202600027744633e-03, -1.713476818001556e-04, -4.202555912070449e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_mcweeny_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_mcweeny", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.996395144513316e-02, -9.996873668261672e-02, -9.988833190457541e-02, -9.989853278978440e-02, -9.977517798309288e-02, -9.979721141229925e-02, -9.960269931124265e-02, -9.965120321157438e-02, -9.933235805197727e-02, -9.944211069511193e-02, -9.889011700522210e-02, -9.914857240092616e-02, -9.811678166301741e-02, -9.876179078677408e-02, -9.661492521129141e-02, -9.836630886398164e-02, -9.319010417973472e-02, -9.855439245220567e-02, -8.355905690802309e-02, -1.027354165792066e-01, -5.498758887138078e-02, -1.283314231883024e-01, -2.157169168079754e-02, -1.836981313529011e-01, -1.878903818880576e-02, -1.846393179888302e-01, -1.943285534396082e-02, -1.697187599659029e-01, -1.605586421186500e-02, -1.532606640874585e-01, -1.003928612573991e-02, -1.258690479126131e-01, -4.061374843158437e-03, -8.193653224539232e-02, -8.052517918796026e-04, -3.523268688691523e-02, -5.940202919896658e-05, -8.462594769729942e-03, -1.415578619734464e-06, -9.792948693006464e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_mcweeny_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_mcweeny", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.090995131603324e-03, -1.104194298809060e-03, 1.091047657024352e-03, 1.158471085782581e-03, -1.172807249736401e-03, 1.158590084907730e-03, 1.262707420680310e-03, -1.278873271189067e-03, 1.262987944392053e-03, 1.428800078325648e-03, -1.448066458025296e-03, 1.429500227964514e-03, 1.705436940866853e-03, -1.730377809559696e-03, 1.707333796297281e-03, 2.196146821565068e-03, -2.232750413223722e-03, 2.201927981251554e-03, 3.147500389215070e-03, -3.212704390021043e-03, 3.168359686792868e-03, 5.233170277649538e-03, -5.390123693080070e-03, 5.328947314673731e-03, 1.059375020541578e-02, -1.118745007522252e-02, 1.121108242653466e-02, 2.650296568623021e-02, -3.054262461389070e-02, 3.269576471957891e-02, 6.150295284812472e-02, -1.006176880577457e-01, 1.465157947409219e-01, 5.835867779057143e-02, -1.955862027938660e-01, 5.358967154301874e-01, 7.465465861751128e-02, -2.757022409904109e-01, 8.031150499559496e-01, 1.445793335734460e-01, -5.155042862760802e-01, 1.393252700337747e+00, 3.548681688031898e-01, -1.421715837829501e+00, 3.864854604440324e+00, 1.119266225983493e+00, -6.003897526842078e+00, 1.721243369045047e+01, 4.389052068375445e+00, -3.991864665164832e+01, 1.231074286454861e+02, 2.116086865091969e+01, -4.473354369154239e+02, 1.514690395213110e+03, 1.497326959403709e+02, -1.067453164672800e+04, 3.979237834587511e+04, 2.481367107161680e+03, -8.616541498757047e+05, 3.383623871201197e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
