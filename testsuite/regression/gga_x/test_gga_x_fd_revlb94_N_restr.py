
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_fd_revlb94_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_fd_revlb94", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.292594618923968e+00, -4.210873517704106e+00, -4.096492234852052e+00, -3.938322153098256e+00, -3.723391195711525e+00, -3.438638449567778e+00, -3.075038332321337e+00, -2.635210898484611e+00, -2.144078882995158e+00, -1.649980370084547e+00, -1.132494694719298e+00, -6.625101070500309e-01, -5.615817909745907e-01, -4.708307302856674e-01, -3.532031893144129e-01, -2.597951010632941e-01, -2.487992501728254e-01, -3.917583341867095e-01, -8.102441896703032e-01, -1.712722777439218e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_fd_revlb94_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_fd_revlb94", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.380647937811835e+00, -5.265496443294141e+00, -5.103935104883197e+00, -4.879697090041728e+00, -4.573221007257776e+00, -4.163362371986970e+00, -3.631692827879595e+00, -2.970576658170949e+00, -2.196628642485317e+00, -1.384374841181077e+00, -8.230427325654024e-01, -7.964729539883717e-01, -7.159536799283315e-01, -5.505999639270609e-01, -3.327372401073399e-01, -1.125131341281192e-01, 8.887075594279739e-02, 2.791000750210892e-01, 4.687108676296368e-01, 6.610313908065926e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_fd_revlb94_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_fd_revlb94", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.678302144921118e-06, -3.988932118031781e-06, -4.481578691074606e-06, -5.296950740593385e-06, -6.731666498942356e-06, -9.487777923425871e-06, -1.549104296540364e-05, -3.113158625069832e-05, -8.354530220637646e-05, -3.282024027762044e-04, -1.829656786391549e-03, -6.971032108989049e-03, -1.219376739008775e-02, -2.867219015687307e-02, -1.302207888828125e-01, -1.252377433027462e+00, -2.851237402211325e+01, -1.805960168320858e+03, -4.217518488570076e+05, -6.226043711541914e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_fd_revlb94_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_fd_revlb94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.249535670926128e-02, -1.310183667983748e-02, -1.402976525780020e-02, -1.548936169316215e-02, -1.788018393248169e-02, -2.203762858190881e-02, -2.994077277405887e-02, -4.711322491544415e-02, -9.251059173666126e-02, -2.441495988855557e-01, -6.744722064291506e-01, -6.081671400055096e-01, -6.844688391586081e-01, -1.318329619953182e+00, -4.169636833262771e+00, -2.583878960078467e+01, -3.797971683346918e+02, -1.510098880746184e+04, -2.164272771106942e+06, -1.990812921437555e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_fd_revlb94_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_fd_revlb94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.661397633019078e-08, 3.065911341518619e-08, 3.756819798715091e-08, 5.029202305875852e-08, 7.640539701171916e-08, 1.390321527482657e-07, 3.269006507154321e-07, 1.103524899259183e-06, 6.160700831887936e-06, 6.674572218713977e-05, 1.341596873874097e-03, 1.440321103873624e-02, 3.865766768579040e-02, 1.705509758946493e-01, 2.369021840458658e+00, 1.211096491845284e+02, 2.779103835738533e+04, 4.054184431843585e+07, 7.381954187574849e+11, 5.415977510535624e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_fd_revlb94_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_fd_revlb94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.279778674183485e-15, 1.044859997026034e-14, 1.459248559678512e-14, 2.356339679484105e-14, 4.681522864625821e-14, 1.249452569270023e-13, 5.066063771261879e-13, 3.699756781669943e-12, 6.120016126367164e-11, 3.014287112787958e-09, 4.711053967239418e-07, 4.849941057944650e-05, 3.282701258845943e-04, 3.133326846338237e-03, 2.096508452657561e-01, 1.195799517381436e+02, 7.402827702749306e+05, 7.723167538370038e+10, 3.350674200163523e+17, 3.401095141748981e+26]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
