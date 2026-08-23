
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_scanl_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_scanl", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.650590933772960e-02, -2.645852264957942e-02, -2.638826513599936e-02, -2.628271294704135e-02, -2.612112131063542e-02, -2.586710763481015e-02, -2.547523330052571e-02, -2.534537881911481e-02, -2.460500548746452e-02, -2.431632460978505e-02, -3.103622208333940e-02, -5.325050126611437e-02, -2.964816655100819e-02, -2.576072460881969e-02, -2.270108498508649e-02, -1.878577680744951e-02, -1.025056970778330e-02, -3.523558633452516e-03, -5.813681209126642e-04, -3.057790856529093e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_scanl_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_scanl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.895413328703132e-02, -2.898406867373029e-02, -2.902840247071145e-02, -2.909477551723171e-02, -2.919545262469928e-02, -2.935010716007085e-02, -3.221240736825466e-02, -4.878944071547440e-02, -5.607083801747105e-02, -7.441269848851237e-02, -6.271122388411730e-02, -8.241157664697529e-02, -6.918687781247537e-02, -6.259923426986684e-02, -6.643656023653544e-02, -4.443196249315496e-02, -2.049339443371478e-02, -6.607620452362253e-03, -1.114775828527265e-03, -6.012284117324475e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_scanl_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_scanl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.371955355447522e-08, 2.611696784400129e-08, 2.998213781022547e-08, 3.652836645840413e-08, 4.841930190184473e-08, 7.226012328933709e-08, 1.817167871374597e-07, 1.212599793566540e-06, 4.632877513866233e-06, 3.224517353558028e-05, 1.183563224764652e-04, 3.182136935526379e-03, 7.078812416189410e-03, 1.268626364728594e-02, 6.242047062232721e-02, 2.153852165253730e-01, 8.679403472426577e-01, 5.590115171820127e+00, 1.049833633943326e+02, 4.233561248129542e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_scanl_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_scanl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, -4.827777015444328e-06, -4.676926597577221e-05, -8.987654760253739e-05, -2.372286819811650e-04, -1.018929741527696e-04, -4.321931889987969e-04, -3.219782894062526e-03, -3.185198315139339e-03, -5.225499011013782e-03, -2.447370005143376e-03, -5.280839565723251e-04, -2.805731857123009e-06, 4.521173984381387e-07, 3.326916702702172e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_scanl_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.513226545790466e-05, 1.648709703386405e-05, 1.862743596073629e-05, 2.214141532716407e-05, 2.821908087450274e-05, 3.945716610343205e-05, -3.430467854337895e-03, -7.985591799978100e-03, -1.582179749149104e-02, -5.124586294072283e-02, -2.986892009472333e-02, -8.245194436547884e-03, -2.539194023903423e-01, -6.146656024608773e-01, -2.691011603289423e+00, 1.493411462848783e+02, -7.540115550472735e+00, -1.796445446371033e+02, -3.550175484172118e+03, -1.492434225794811e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_scanl_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.751571527253743e-10, -2.031722513468020e-10, -2.512012925914131e-10, -3.399606642152380e-10, -5.222494862107825e-10, -9.553931378300322e-10, 7.098738048856049e-08, 4.064709940798758e-07, 2.460562941675987e-06, 3.716803316858926e-05, 9.250843451712207e-05, 2.268042145750882e-03, 3.946092731728480e-02, 2.095625052185751e-01, 4.377665893592577e+00, -2.153578886088348e+03, -1.130129900249992e+03, 3.208009241750906e+05, 6.946920969349282e+08, 2.107630984048965e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_scanl_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, -6.492366144314484e-06, -2.082713349859150e-05, -5.969618532320402e-05, -3.219294578400866e-04, -4.697976335714382e-05, -1.009413468783787e-03, -2.250614451029348e-02, -6.505468633070879e-02, -4.441116201231085e-01, 3.811676699601895e+01, 3.037021831374495e+00, 3.123446316256175e-01, 7.161050854594200e+00, 3.768123563446587e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_scanl_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.696071018165020e-16, -6.065521016810274e-16, -8.755956693540363e-16, -1.481607401061909e-15, -3.143008256067181e-15, -9.179977867408410e-15, -1.614632806938489e-12, -2.383765741026240e-11, -4.441332414754944e-10, -3.067269795800821e-08, -4.913535572115131e-07, -8.562674705345025e-04, -1.305016509732311e-02, -1.082166753401570e-01, -8.681028167222198e+00, 3.076971027623700e+04, 4.041728823417494e+05, -1.219612110345039e+09, -3.243033057217159e+14, -7.423882866005319e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_scanl_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 1.377832580671561e-10, 1.115055465491252e-09, 9.658020577882546e-09, 2.338574737710383e-07, -2.038717038225014e-07, 2.011974361066769e-05, 5.232108462789571e-03, 2.629245668130547e-02, 7.354517943268603e-01, -5.467430330826899e+02, -8.645456904710707e+02, -5.118081553254097e+03, -3.368881279291174e+06, -1.297262736642679e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_scanl_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, -1.207725468866330e-08, -5.305837653335853e-08, -2.137147724736106e-07, -1.814202200599234e-06, 1.221326110442975e-06, 3.495661963184140e-05, -2.167127199350771e-03, -6.534768218644568e-03, -6.360137188849518e-02, 9.678401997299394e+00, 1.399146765715942e+00, 2.812001341578083e-01, 6.362359595235301e-01, 2.927780554066742e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
