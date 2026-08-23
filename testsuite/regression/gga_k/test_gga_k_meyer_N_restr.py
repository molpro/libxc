
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_meyer_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_meyer", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.394127303813671e+01, 9.028797833712112e+01, 8.529296865687796e+01, 7.861307282897415e+01, 6.995876485231875e+01, 5.924263559756775e+01, 4.680017324582381e+01, 3.360850950393780e+01, 2.129410497764329e+01, 1.160715116140973e+01, 5.186705375235570e+00, 2.191402249584671e+00, 1.621796445547477e+00, 1.091917488194866e+00, 5.573066055549106e-01, 2.350308853815776e-01, 1.300359826572604e-01, 5.537930784298662e-01, 5.989215805687372e-01, 5.741849775858511e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_meyer_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_meyer", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.493063823461089e+02, 1.432303809684348e+02, 1.349242067219358e+02, 1.238187089129420e+02, 1.094351866866582e+02, 9.163281441523951e+01, 7.097658962890802e+01, 4.910583613316260e+01, 2.878281361558527e+01, 1.326315223095361e+01, 5.231002323780641e+00, 3.370604795281233e+00, 2.611758672577169e+00, 1.643031597632088e+00, 7.025558883934938e-01, 1.469918776141274e-01, -1.400308581928544e-01, -8.081735571483686e-01, -6.092384357022393e-01, -5.743108302985948e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_meyer_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_meyer", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.792422231815983e-05, 8.285949351037006e-05, 9.050334851184393e-05, 1.027314118777458e-04, 1.232231120551961e-04, 1.599326202573329e-04, 2.323102397502819e-04, 3.960456380857770e-04, 8.462950755650831e-04, 2.447476973689732e-03, 9.091700733259203e-03, 2.260708716124133e-02, 3.389500590265510e-02, 6.569707611577998e-02, 2.132227736708273e-01, 1.310454992005817e+00, 2.418432820308961e+01, 3.900968282670344e+03, 4.376535113207391e+05, 3.237673137497776e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_meyer_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_meyer", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.968751456157524e-01, 6.104560378502601e-01, 6.305984828567491e-01, 6.608902762174672e-01, 7.073916063841353e-01, 7.810201852220687e-01, 9.033079708403535e-01, 1.122530062603611e+00, 1.567660826720638e+00, 2.637907890606936e+00, 4.586218324060878e+00, 4.092915703066279e+00, 4.458561488403081e+00, 5.978933842655923e+00, 1.062460781362950e+01, 3.488919949031709e+01, 9.115996772106790e+02, 3.557707491496510e+04, 4.205718271201106e+06, 2.974545875353242e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_meyer_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_meyer", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.406557406125545e-07, -4.983951812654347e-07, -5.948689050260745e-07, -7.670245193284095e-07, -1.104783460877705e-06, -1.864540079953167e-06, -3.946697819381317e-06, -1.154033302976148e-05, -5.335561675345094e-05, -4.579009515678145e-04, -6.433701965436937e-03, -3.728940635843845e-02, -8.319191319079304e-02, -3.160427945350959e-01, -3.424023076863004e+00, -1.417481648902559e+02, -6.824073912987504e+04, -1.178905619333975e+08, -1.532255472689510e+12, -8.386021814772960e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_meyer_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_meyer", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.939579143201168e-14, 7.436813105418564e-14, 1.027222240638398e-13, 1.633456658606156e-13, 3.178022667219192e-13, 8.249709395187140e-13, 3.230435057272043e-12, 2.267761702279218e-11, 3.615748774771592e-10, 1.718409795446895e-08, 2.063217196914118e-06, 6.315796736948936e-05, 2.813365348738612e-04, 3.143040097025514e-03, 2.275736433279315e-01, 1.562439124642690e+02, 2.956584826692986e+06, -7.466624104589383e+09, -1.590238738828746e+13, -1.094075885946422e+18]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
