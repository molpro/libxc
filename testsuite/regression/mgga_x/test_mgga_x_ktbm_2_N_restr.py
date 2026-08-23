
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.794514606644019e+00, -4.700811484634277e+00, -4.569525915260911e+00, -4.387684251142414e+00, -4.139911816082311e+00, -3.810038487277011e+00, -3.384737063920092e+00, -2.859087326245144e+00, -2.240678873091738e+00, -1.558375446148725e+00, -9.477770794446565e-01, -6.236305482770309e-01, -5.717983646205148e-01, -4.895782174381623e-01, -3.438535917003939e-01, -1.924462155371518e-01, -8.320580033734948e-02, -2.649518908583689e-02, -5.487181853198364e-03, -6.071742495618382e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.972259272486542e+00, -5.841508735317806e+00, -5.658210336757429e+00, -5.404167030292356e+00, -5.057899218497962e+00, -4.597446803969610e+00, -4.007973791571803e+00, -3.299494733091470e+00, -2.538805458767405e+00, -1.820504194752916e+00, -1.155878310345080e+00, -7.929713438881316e-01, -7.931944784486025e-01, -6.151628637476643e-01, -4.051451231214188e-01, -2.358441970520456e-01, -1.059579258571511e-01, -3.404722489901338e-02, -7.056023057977891e-03, -7.805970946319599e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.063171449228594e-06, -8.726071933790939e-06, -9.772305853333802e-06, -1.149052847006940e-05, -1.447494466199069e-05, -2.007692066363030e-05, -3.173790872563381e-05, -5.920476135865645e-05, -1.303710597511237e-04, -3.018635500949217e-04, -7.457944100793405e-04, -4.480122410203874e-03, -2.027218855571538e-02, -4.828234098349654e-02, -1.417400004622824e-01, -3.792603280705332e-01, -1.088328189634543e+00, -7.966829540092156e+00, -1.892903922500945e+02, -1.633367175092711e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_2_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.080467419643862e-03, 8.244556615123430e-03, 8.485509446880432e-03, 8.842220833493257e-03, 9.375810718353554e-03, 1.018292119844180e-02, 1.140795003982535e-02, 1.318270403515158e-02, 1.496383606139590e-02, 1.290471060003303e-02, 5.413147702006205e-03, 1.506807357685519e-03, 3.399623706655632e-02, 5.397596725018110e-02, 6.024687623457001e-02, 3.417586255498609e-02, 8.533560962079615e-03, 1.966818893087604e-03, 4.182179307369051e-04, 4.957338397622670e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.553018910433829e-02, -1.628910981192152e-02, -1.744275146930890e-02, -1.923625122033949e-02, -2.210826379314051e-02, -2.686982908654903e-02, -3.496066852790561e-02, -4.792530435375560e-02, -6.026768103261614e-02, -5.981152252085740e-02, -1.408636414638306e-01, -5.503555917718705e-01, -9.158142613367652e-01, -1.379972711434660e+00, -1.763996752501859e+00, -2.942752240158230e+00, -2.761768479465929e+01, -3.146914871924508e+02, -7.458682217689017e+03, -6.095371756650958e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.627460494148920e-08, 6.444790520307756e-08, 7.824246079638135e-08, 1.031597456852976e-07, 1.526298414994575e-07, 2.641904134297370e-07, 5.584625605029015e-07, 1.438125866873716e-06, 3.060011139883297e-06, -2.462255781160074e-05, -4.803068232540229e-04, -4.308949637888717e-03, 3.328263582807103e-02, 1.441767114530282e-01, -4.572603733079876e-01, -4.151312553246674e+01, -1.402302640329874e+03, -2.263221230165287e+05, -5.635569247445999e+08, -3.631865325034605e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_2_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.027523111795898e-05, -2.221871602485479e-05, -2.534678663604282e-05, -3.063313209920854e-05, -4.020439482541808e-05, -5.925183158268414e-05, -1.018754817485033e-04, -2.055510399978558e-04, -3.705254665158172e-04, 4.727675259609498e-04, 2.558205033747840e-03, 1.544343004477835e-02, 7.295809294690628e-02, 1.863002323686341e-02, 1.449300933657098e-01, 2.690474355337670e+00, 9.510553598454120e+00, 5.450152235952618e+01, 1.243730525985984e+03, 1.102271741678019e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.134876427709034e-14, -3.953022482267060e-14, -5.509378139834889e-14, -8.850182822209485e-14, -1.735939257275714e-13, -4.486743170196360e-13, -1.671604104822067e-12, -9.529019967147948e-12, -6.200418915511843e-11, 1.906833157055890e-09, 2.321124990412375e-07, 7.147274631238765e-06, -4.756217546166215e-04, -5.291774577184482e-03, 4.821220955299971e-02, 7.162582309829007e+01, 6.828441223758657e+04, 6.999676094490923e+08, 2.460489221388879e+14, 1.252446806743437e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_2_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.630226954790188e-10, 1.975290092802002e-10, 2.602713812235602e-10, 3.867183430498700e-10, 6.821458368227150e-10, 1.534793193947818e-09, 4.848913094238300e-09, 2.406526718197569e-08, 1.997402562364129e-07, 2.308599897411097e-06, 3.181849804860212e-05, 1.207911929909206e-03, 1.343511351935954e-02, 1.002184004241759e-01, 2.002161330885823e+00, 4.884918467274692e+01, 1.443369450573648e+03, 2.142536030130052e+05, 5.225217833262325e+08, 3.438682896762697e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_2_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.430715563976521e-07, -2.781704922292780e-07, -3.377512576137141e-07, -4.465415054920036e-07, -6.671763697558349e-07, -1.187327711131032e-06, -2.703704550944715e-06, -8.564007979532948e-06, -3.866060642945814e-05, -1.817149422197337e-04, -4.912988993915717e-04, -2.727512866449134e-03, -5.443390497690215e-02, -2.177846577761094e-01, -1.594305453219521e+00, -8.730050102737964e+00, -2.597432055205258e+01, -1.481800386883678e+02, -3.509970982533298e+03, -3.240998635796048e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
