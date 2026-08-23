
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_ak13_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ak13", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.358541908230870e+00, -4.279251914163042e+00, -4.168470580191395e+00, -4.015698033620940e+00, -3.809002513021728e+00, -3.537119789786713e+00, -3.194264119761577e+00, -2.789004844759364e+00, -2.355893165749385e+00, -1.942374700699714e+00, -1.388976270505264e+00, -6.833738058899407e-01, -5.669267795978568e-01, -4.910181037726402e-01, -4.001898253555121e-01, -3.527131628884265e-01, -4.201951696357409e-01, -6.682469652432896e-01, -1.155292764719066e+00, -1.941601969237557e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_ak13_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ak13", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.211605287217206e+00, -5.091829650851899e+00, -4.923498791701126e+00, -4.689277421930812e+00, -4.367930519267015e+00, -3.935636348353579e+00, -3.369651497180507e+00, -2.655766275980780e+00, -1.804030724558513e+00, -9.076877919490547e-01, -4.305256493111281e-01, -7.489847807936766e-01, -7.010928412989140e-01, -5.069860392570249e-01, -2.508997300587857e-01, 1.054731543534830e-02, 2.379710066977690e-01, 3.979840344083659e-01, 4.823804240345281e-01, 5.176177330287984e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ak13_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ak13", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.435566324835988e-06, -7.015911979704891e-06, -7.941223942383511e-06, -9.484140513573727e-06, -1.222707408948143e-05, -1.756969760088147e-05, -2.941600061560865e-05, -6.093493276472208e-05, -1.687149391108589e-04, -6.769062827142059e-04, -3.785940126461177e-03, -1.301385819304920e-02, -2.036237387833809e-02, -5.487599842232786e-02, -2.663646418318172e-01, -2.574746454115198e+00, -5.411150806018146e+01, -2.904563517955707e+03, -5.507341760013602e+05, -6.568057899727310e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ak13_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ak13", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.525901528547243e-02, -1.610247225165708e-02, -1.740496457212775e-02, -1.948109461424727e-02, -2.294677801100645e-02, -2.913590928343392e-02, -4.133488430636766e-02, -6.907154306877784e-02, -1.458473035196703e-01, -4.081871892675792e-01, -1.141855168863231e+00, -8.148435076954886e-01, -7.955810876751636e-01, -1.847050092181922e+00, -6.801286144565063e+00, -4.348146631961676e+01, -5.480313237155893e+02, -1.673705891411307e+04, -1.862835356695593e+06, -1.384072246954628e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ak13_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ak13", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.964351203689137e-08, 6.888283573101350e-08, 8.469364158523715e-08, 1.138807889230350e-07, 1.739457841447126e-07, 3.183446492389466e-07, 7.516298770358945e-07, 2.531651257301501e-06, 1.387550970353958e-05, 1.436026234134282e-04, 2.803358214873553e-03, 3.303849160851759e-02, 8.441292770796661e-02, 3.922714232754259e-01, 5.232374483195676e+00, 2.344508230575380e+02, 4.262622358891366e+04, 4.700301385186101e+07, 6.604674521218054e+11, 3.871316143295094e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ak13_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ak13", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.258556479791271e-13, -1.525882793769014e-13, -2.009899620849129e-13, -2.977254602144960e-13, -5.199509847318901e-13, -1.139075710054890e-12, -3.366785379890851e-12, -1.406643529428088e-11, -5.738481949743831e-11, 3.825827548761556e-09, 9.020615961977612e-07, -4.029450636634309e-04, -6.829477428458854e-03, -1.846881219299078e-02, 6.458180287532539e-02, 3.236848948746841e+02, 2.090705028786696e+06, 1.652277503440747e+11, 5.201689477097881e+17, 3.977427350295610e+26]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
