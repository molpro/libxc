
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_llp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_llp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.465201916510112e+01, 9.098409376693833e+01, 8.596768453783154e+01, 7.925630016777784e+01, 7.055529714873646e+01, 5.976923452915324e+01, 4.722075869912026e+01, 3.386657456951408e+01, 2.130645195413780e+01, 1.131525996431179e+01, 4.938159857512831e+00, 2.211084804860504e+00, 1.632008317410409e+00, 1.101591757895035e+00, 5.523238333053624e-01, 2.040739805072963e-01, 5.591274384815181e-02, 1.101872803406834e-02, 1.462775389951667e-03, 1.120416095719646e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_llp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_llp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.494973391018803e+02, 1.434518182655795e+02, 1.351898323614891e+02, 1.241485757673071e+02, 1.098587649650484e+02, 9.219355029106761e+01, 7.173817602787176e+01, 5.015762668153852e+01, 3.022310950007073e+01, 1.502815805889103e+01, 6.333981536144486e+00, 3.395367653145906e+00, 2.611112419565159e+00, 1.664038274093686e+00, 7.597015003676436e-01, 2.415453781320824e-01, 5.432731523571677e-02, 8.624112790070778e-03, 8.903724007379688e-04, 5.571698182283664e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_llp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_llp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.858557542679220e-05, 9.358904467660835e-05, 1.012537543986340e-04, 1.133164777006870e-04, 1.330400487358028e-04, 1.670667395848876e-04, 2.303055307092120e-04, 3.604054902197397e-04, 6.671635299092717e-04, 1.541462105575442e-03, 5.050658046495568e-03, 2.325235452974203e-02, 4.045814356141601e-02, 6.388295954599271e-02, 1.515515755663177e-01, 5.278629618516094e-01, 2.634330888257916e+00, 2.194891256177715e+01, 4.213570964174974e+02, 2.770200110654185e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_llp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_llp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.829724780795639e-01, 5.951763920681035e-01, 6.131316045043265e-01, 6.398000079884061e-01, 6.799339606042989e-01, 7.414169744175497e-01, 8.377890156512634e-01, 9.928572849039941e-01, 1.247677397989150e+00, 1.669345011618669e+00, 2.469926894224580e+00, 3.860439082257291e+00, 4.404451270993773e+00, 5.491754393752551e+00, 7.680650336017794e+00, 1.123649328895593e+01, 1.480664163974032e+01, 7.079894260527179e+00, -6.545946279218676e+02, -6.143299282669574e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_llp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_llp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.838554593914771e-07, -3.137392222146614e-07, -3.618776705492734e-07, -4.431641762643412e-07, -5.895941303312592e-07, -8.768916543402645e-07, -1.501409512835384e-06, -2.975190154261083e-06, -5.754081753941568e-06, 1.218114289749441e-05, 4.219770965906919e-04, -1.649583482377592e-02, -6.347861859902722e-02, -1.106838932324838e-01, -1.142524203618566e-01, 1.390213582487246e+01, 1.496352550960261e+03, 3.865804185156434e+05, 7.440639567219645e+08, 3.333119384063903e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_llp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_llp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.261805949698282e-12, -2.764173421698960e-12, -3.685733304822717e-12, -5.565926894944844e-12, -1.003400695390089e-11, -2.324254810797708e-11, -7.654936780635699e-11, -4.108539991763099e-10, -4.296084544434223e-09, -1.101304667306908e-07, -9.497116585485726e-06, -1.688987117881159e-03, -1.297242317228475e-02, -6.999739687371412e-02, -2.023754749687246e+00, -3.172504970756899e+02, -2.832801974461823e+05, -2.407825318959488e+09, -6.042482979361622e+14, -2.221826255638084e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
