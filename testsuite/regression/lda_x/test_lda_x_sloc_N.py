
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_sloc_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_sloc", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.091049127064502e+00, -5.980201159059287e+00, -5.824466332285888e+00, -5.607915207031444e+00, -5.311224108934572e+00, -4.913253441578634e+00, -4.395300050378858e+00, -3.749533820801937e+00, -2.992857217425625e+00, -2.188567904288983e+00, -1.495406222493249e+00, -1.175773224339737e+00, -1.047277259672925e+00, -8.573222249377841e-01, -6.097956664629842e-01, -3.674954919987468e-01, -1.805621754639851e-01, -6.736794006514053e-02, -1.687211328085614e-02, -2.360629547441827e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_sloc_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_sloc", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.918392779600993e+00, -7.918334950062810e+00, -7.774322086347265e+00, -7.774200924059679e+00, -7.571933868162027e+00, -7.571678581436109e+00, -7.290560906006719e+00, -7.290018565031771e+00, -6.905174335490601e+00, -6.904008019384524e+00, -6.388505807498429e+00, -6.385951438041200e+00, -5.716760779510044e+00, -5.711009703970053e+00, -4.881116388760935e+00, -4.867609163165573e+00, -3.907379751448639e+00, -3.873559026449199e+00, -2.888810284244723e+00, -2.796471578404052e+00, -2.045150644518927e+00, -1.784827388812766e+00, -1.643657311979717e+00, -1.152295440426738e+00, -1.462964569938658e+00, -9.968548926732025e-01, -1.198137378343517e+00, -8.283022650689863e-01, -8.513788217147765e-01, -5.722011505074004e-01, -5.107722193372193e-01, -3.188011000394921e-01, -2.479563392191138e-01, -1.354290583461344e-01, -9.063042849697860e-02, -3.967831992679492e-02, -2.223982665282505e-02, -6.916835262419419e-03, -3.079426574215594e-03, -6.003934177542131e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_sloc_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_sloc", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.652892955321609e-02, 0.000000000000000e+00, -2.652938163237019e-02, -2.769025270752592e-02, 0.000000000000000e+00, -2.769125968538238e-02, -2.944807602191792e-02, 2.940955026951252e-133, -2.945039277386267e-02, -3.216848602839563e-02, -2.940955026951252e-133, -3.217407037967594e-02, -3.651449591265463e-02, -5.881910053902503e-133, -3.652889072441377e-02, -4.377987007462996e-02, 8.822865080853755e-133, -4.382074200556307e-02, -5.673565970577385e-02, 0.000000000000000e+00, -5.686906116001823e-02, -8.203416708379473e-02, -2.940955026951252e-132, -8.256630589883925e-02, -1.378710354064586e-01, -8.234674075463505e-132, -1.406962119868708e-01, -2.789513305904157e-01, -4.705528043122003e-132, -3.009182526812474e-01, -6.244731637625635e-01, 1.411658412936601e-131, -8.579888358331016e-01, -1.039871901762568e+00, 0.000000000000000e+00, -2.381718991001018e+00, -1.364564078015777e+00, 1.882211217248801e-131, -3.339885792905450e+00, -2.174489830950843e+00, -3.764422434497602e-131, -5.145554390932222e+00, -4.825987444823307e+00, -3.011537947598082e-130, -1.219717135794473e+01, -1.589800131255963e+01, -1.355192076419137e-129, -4.775218640750102e+01, -8.583491547497322e+01, 4.818460716156931e-129, -3.520020156794081e+02, -8.986006804486855e+02, 0.000000000000000e+00, -6.174216389973711e+03, -2.383597342693106e+04, 9.251444575021307e-127, -3.637101985250666e+05, -2.403125747922947e+06, -4.342011320543333e-124, -1.090240561191005e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
