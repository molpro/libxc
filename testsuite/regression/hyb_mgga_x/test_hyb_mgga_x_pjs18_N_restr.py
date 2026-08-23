
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_pjs18_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pjs18", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.467081449094387e+00, -4.374361443852585e+00, -4.244498862799356e+00, -4.064735251817524e+00, -3.820058409087705e+00, -3.494999085463236e+00, -3.077861000140435e+00, -2.568244422670020e+00, -1.986556511346182e+00, -1.376845966571211e+00, -7.864164793744010e-01, -3.989029651113403e-01, -4.013435824679215e-01, -3.089821868845892e-01, -1.730522780658448e-01, -6.009710641459995e-02, -9.087483583084834e-03, -4.016079515759455e-04, -3.851092402733292e-06, -5.196812919738392e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_pjs18_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pjs18", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.823806774241898e+00, -5.695402891382128e+00, -5.515284161814313e+00, -5.265390235508704e+00, -4.924141940924315e+00, -4.468668684247429e+00, -3.880602746105910e+00, -3.158054089465047e+00, -2.336819271717150e+00, -1.515115346892941e+00, -8.440884552172880e-01, -6.728994914297005e-01, -6.174477704913285e-01, -4.424679303848026e-01, -2.330989744011651e-01, -7.356271689527881e-02, -9.318984894942279e-03, -3.505727310319806e-04, -3.250437112120507e-06, -4.480394244359954e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pjs18_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pjs18", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.951120846842397e-06, -4.287889755524469e-06, -4.821215880330935e-06, -5.701471002064075e-06, -7.241845494168963e-06, -1.016749884501088e-05, -1.638759412492618e-05, -3.176459423869841e-05, -7.794832304569622e-05, -2.585550450622026e-04, -1.444950759808125e-03, -1.164811500423689e-02, -1.271750753147027e-02, -2.299384012870295e-02, -6.979512986374292e-02, -2.645915454603239e-01, -8.407468106003387e-01, -1.572356747257588e+00, -1.909527435780121e+00, -1.972224737305687e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pjs18_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pjs18", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.236396899706541e-03, 4.295194781040522e-03, 4.379731623594672e-03, 4.501038998785315e-03, 4.674285923743280e-03, 4.918978238270339e-03, 5.255891982351778e-03, 5.693870551443885e-03, 6.199152571061817e-03, 6.748011811764464e-03, 8.716239248464869e-03, 2.111147825500287e-02, 2.629050127994009e-02, 2.436261606088825e-02, 2.028159176936242e-02, 1.128635125727357e-02, 2.452098947142692e-03, 1.304254051576410e-04, 1.341066787303382e-06, 1.857264339443599e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pjs18_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pjs18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.383774971988423e-02, -1.449303965252864e-02, -1.548936633176769e-02, -1.704025497180441e-02, -1.953463315017525e-02, -2.372760149466809e-02, -3.118027336566753e-02, -4.523925385484347e-02, -7.273899349324030e-02, -1.271507940078573e-01, -3.065096270662627e-01, -8.548437497566499e-01, -7.838175785928256e-01, -1.302040386169966e+00, -2.604305869231462e+00, -5.448983641531103e+00, -9.718717084875303e+00, -1.291972600134066e+01, -1.418059068279927e+01, -1.440718641745268e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pjs18_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pjs18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.745053909215306e-08, 3.133901203808083e-08, 3.785758708688022e-08, 4.950987350789196e-08, 7.227057270579868e-08, 1.223316433195324e-07, 2.499476594506112e-07, 6.255208309023738e-07, 1.638063909106294e-06, -3.561302792561250e-06, -2.158028051178448e-04, 2.170834596123368e-02, 4.551098583381146e-02, 1.034592120793688e-01, 3.831790188897078e-01, -1.708736342414080e+00, -1.224410004099592e+02, -2.507676252420448e+03, -5.300233880147833e+04, -2.739097338788516e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pjs18_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pjs18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.443687683565004e-06, 2.945305504297973e-06, 3.787119543177030e-06, 5.289269399338686e-06, 8.201803147550481e-06, 1.450763251185521e-05, 3.026243503860539e-05, 7.738083272530033e-05, 2.519003245074484e-04, 1.065535447385841e-03, 5.661525162961130e-03, 1.163586025766342e-02, 7.537596855067347e-03, 5.325143376314809e-02, 2.567970671169130e-01, 1.122791396544869e+00, 2.967394600646160e+00, 4.318400131980427e+00, 4.744035728064143e+00, 4.814087468914031e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pjs18_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pjs18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.798706101122689e-14, 8.856239744739868e-14, 1.291789320524906e-13, 2.210736183628157e-13, 4.733786611086044e-13, 1.383226814510579e-12, 6.179129342505683e-12, 4.863351467798208e-11, 7.970015006756868e-10, 3.337693924784433e-08, 5.290190602440338e-06, 1.472713022484578e-03, 2.834072407694342e-03, 2.237555293010917e-02, 1.024480764370273e+00, 1.456564689877858e+02, 4.205899569330906e+04, 2.402119926441830e+07, 6.088059977817313e+10, 2.512482606589961e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pjs18_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pjs18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.099084278524627e-10, -1.297139097637045e-10, -1.644460650309697e-10, -2.308067293304910e-10, -3.740476205579311e-10, -7.414570388363220e-10, -1.941513508955093e-09, -7.414740249042565e-09, -4.670932174456607e-08, -5.717749514276666e-07, -1.921365594705889e-05, -1.543653576192989e-03, -7.204989580953542e-03, -2.567335785374127e-02, -2.479899723763086e-01, -4.788867509208113e+00, -9.724700600359668e+01, -1.622190084321575e+03, -3.537365064545078e+04, -1.982197343205380e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pjs18_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pjs18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
