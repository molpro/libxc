
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_rational_p_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_rational_p", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.102812084967650e+01, 7.743771478337523e+01, 7.253573166483838e+01, 6.599459508643439e+01, 5.754932552894581e+01, 4.715206204630888e+01, 3.520500765926244e+01, 2.280733919139811e+01, 1.182556270771219e+01, 4.426625567095794e+00, 1.558630135939607e+00, 1.716148062902616e+00, 1.455941897429252e+00, 8.034146024736595e-01, 2.625172543229392e-01, 3.584287178296917e-02, 1.118549268241235e-03, 5.024276039324920e-06, 2.166381337467406e-09, 3.854229904905566e-14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_rational_p_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_rational_p", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.596715845972592e+02, 1.534554596612768e+02, 1.449427888620590e+02, 1.335304463088251e+02, 1.186863203640052e+02, 1.001846058850939e+02, 7.845610062153511e+01, 5.494823423083135e+01, 3.229178737827809e+01, 1.434331385860738e+01, 5.471706274573034e+00, 3.698081698435448e+00, 2.753262177573363e+00, 1.822385684933131e+00, 7.790652940661738e-01, 1.472744613550211e-01, 5.820120526492000e-03, 2.818134029950238e-05, 1.227034282627906e-08, 2.184050320196236e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_rational_p_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_rational_p", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.642184794923798e-04, -2.787965379203972e-04, -3.010198704008647e-04, -3.357232858312844e-04, -3.917328193727555e-04, -4.861705080224919e-04, -6.542633999121095e-04, -9.709168378753616e-04, -1.587587271072786e-03, -2.803005153697423e-03, -7.654724059480236e-03, -6.723051659204456e-02, -1.213699800383344e-01, -1.795807765762929e-01, -3.218165414474149e-01, -4.687377390025495e-01, -2.681656355409777e-01, -4.463395757918441e-02, -2.357754422104800e-03, -3.259647309149069e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_rational_p_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_rational_p", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.265358880172542e-01, 5.385340121769613e-01, 5.566183523024502e-01, 5.845214050474010e-01, 6.291816175258048e-01, 7.049480549868399e-01, 8.457780216501835e-01, 1.144074198561707e+00, 1.864883718415290e+00, 3.539555130035650e+00, 5.979281662910374e+00, 3.728658441369541e+00, 3.966665190087723e+00, 5.694236380550220e+00, 1.370791713860324e+01, 3.152167178258232e+01, 2.366632193380510e+01, 4.012032422870170e+00, 2.003148360564631e-01, 2.639901298769988e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_rational_p_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_rational_p", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.280851441748199e-07, 7.861598968050493e-07, 8.730023276030853e-07, 1.001305747734315e-06, 1.176044571721693e-06, 1.314609721218443e-06, 6.886606477807615e-07, -6.492001417832630e-06, -7.324814388169920e-05, -7.715712164242752e-04, -9.878022046621290e-03, 2.022586048877473e-02, 1.847890879714373e-01, -2.289353547158078e-03, -5.611956568061963e+00, -1.236291435291228e+02, -1.336486944178077e+03, -7.725263194781899e+03, -4.674125541705758e+04, -4.784283011217957e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_rational_p_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_rational_p", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.018185184033428e-12, 9.931055167407900e-12, 1.349616405246181e-11, 2.093512622220664e-11, 3.917870616885340e-11, 9.548575319545259e-11, 3.357626025174392e-10, 1.938490573665197e-09, 2.119264377589928e-08, 5.018339109267870e-07, 3.899994446548826e-05, 7.087658747400782e-03, 4.101108764461563e-02, 3.132167264469294e-01, 9.813931972101676e+00, 8.776177839934976e+02, 1.091105026137357e+05, 2.053292765802811e+07, 1.497367140408442e+10, 1.190077778607559e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
