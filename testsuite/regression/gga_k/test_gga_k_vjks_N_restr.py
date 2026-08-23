
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_vjks_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vjks", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.433911435571105e+01, 9.066815383757289e+01, 8.564684857114663e+01, 7.892724597453986e+01, 7.021175284875621e+01, 5.939861395293245e+01, 4.679619016204212e+01, 3.332779182095382e+01, 2.052160676741781e+01, 1.011936235539681e+01, 4.091471184583125e+00, 2.195754370257371e+00, 1.628315936286901e+00, 1.090276063551665e+00, 5.180711036041923e-01, 1.086878038980589e-01, -1.793206268159032e-01, -3.475539562890581e-01, -3.597983673547707e-01, -3.445163062376000e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_vjks_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vjks", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.500497949263935e+02, 1.440293746024161e+02, 1.358056929936143e+02, 1.248242821825336e+02, 1.106309633054689e+02, 9.312775839693879e+01, 7.295784721934405e+01, 5.190404022597141e+01, 3.294181389314848e+01, 1.909870839011668e+01, 9.134684564704054e+00, 3.435773153313030e+00, 2.615933072687251e+00, 1.697727353661922e+00, 8.784737301430620e-01, 5.319292878327383e-01, 5.661401707083301e-01, 4.460236293861549e-01, 3.647729687325176e-01, 3.445776276679492e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_vjks_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vjks", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.706214965614146e-05, 8.096941344912535e-05, 8.685246444765932e-05, 9.585774816098378e-05, 1.099055120375852e-04, 1.321330348448140e-04, 1.665601836069007e-04, 2.088066841237354e-04, 1.590883483683401e-04, -8.986159421800297e-04, -6.167391676109388e-03, 1.795981908696705e-02, 3.638094488207001e-02, 4.435985724775476e-02, -1.415454108824254e-02, -1.878365061901646e+00, -5.863824798466850e+01, -2.310347375105376e+03, -2.625845574578307e+05, -1.942603873263768e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_vjks_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vjks", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.670204319620029e-01, 5.773638941339649e-01, 5.922823433800255e-01, 6.137194004561615e-01, 6.441307387379570e-01, 6.855283947491387e-01, 7.339524931178099e-01, 7.505551635660573e-01, 5.035333442383001e-01, -1.211462368470609e+00, -4.494858858097547e+00, 3.520466491167597e+00, 4.348438688863718e+00, 4.688273290947705e+00, -7.939899946150433e-02, -7.943850167261485e+01, -1.250348813257169e+03, -2.394909198279102e+04, -2.525648111374802e+06, -1.784742891468511e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_vjks_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vjks", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.062649088867225e-08, -8.402530188871942e-08, -6.760687179475413e-08, -2.394615104987723e-08, 1.044147900526460e-07, 5.413986951101533e-07, 2.378595364914878e-06, 1.279389060489428e-05, 1.017810398513239e-04, 1.356689129392396e-03, 2.206774730496243e-02, 1.427469981080588e-02, -3.976553589535051e-02, 2.268956219890550e-01, 8.311341704529472e+00, 5.884943136949219e+02, 1.108133804742445e+05, 7.478478017967002e+07, 9.194675400052670e+11, 5.031613192512273e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_vjks_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vjks", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.644700577812723e-12, -4.533451376362523e-12, -6.200524507224260e-12, -9.713534017082652e-12, -1.846465400704844e-11, -4.618102908318829e-11, -1.699484728511723e-10, -1.070308960082667e-09, -1.403967195418768e-08, -4.845961655631511e-07, -4.855174680004372e-05, -3.472390502255192e-03, -1.809820400462894e-02, -1.614577420070220e-01, -7.632384287470130e+00, -2.287242080714840e+03, -3.464255052897101e+06, -6.763967221407933e+09, -2.876333799938039e+13, -2.040791037496512e+18]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
