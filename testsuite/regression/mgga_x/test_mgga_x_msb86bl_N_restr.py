
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_msb86bl_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msb86bl", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.569131168806772e+00, -4.479452694996756e+00, -4.353845427817346e+00, -4.179963021474935e+00, -3.943273819608564e+00, -3.628801166328199e+00, -3.225254319825348e+00, -2.732532368357876e+00, -2.171400578436814e+00, -1.570530766146266e+00, -9.936837742644866e-01, -6.190042036821281e-01, -5.590634919142364e-01, -4.763765711562212e-01, -3.395104121566350e-01, -2.139055555762698e-01, -1.248728629998530e-01, -5.671592464394437e-02, -1.808589382166489e-02, -4.037658714782445e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_msb86bl_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msb86bl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.911115355257961e+00, -5.788330042520895e+00, -5.616151631831945e+00, -5.377370529173507e+00, -5.051409702311345e+00, -4.616253347308016e+00, -4.052998905676984e+00, -3.352775681998464e+00, -2.514441107547249e+00, -1.484652965506045e+00, -9.914906281988805e-01, -8.133132493223211e-01, -7.534669776469435e-01, -6.005520413902740e-01, -3.535841819742742e-01, -1.878748069624272e-01, -9.736517835714362e-02, -5.446128655889780e-02, -1.699789083313879e-02, -3.516726258839636e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_msb86bl_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msb86bl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.962043134031966e-06, -2.128909964966459e-06, -2.394113847223184e-06, -2.834659566239084e-06, -3.615154229217845e-06, -5.135791709051266e-06, -8.559847610961264e-06, -1.834075320319604e-05, -6.232625776004424e-05, -4.846070969560229e-04, -1.344352996186935e-03, -5.654156407018858e-03, -1.259756263574191e-02, -5.130572099636014e-02, -2.100790241055745e-01, -5.967805478584327e-01, -5.590579730362687e+00, -4.775848003620995e+01, -1.937628013987871e+03, -3.947106912866473e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_msb86bl_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msb86bl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.392545249654385e-05, 4.865360321340459e-05, 5.639982768472093e-05, 6.984724482658855e-05, 9.524004354802852e-05, 1.494293252135792e-04, 2.875934354481936e-04, 7.432175331117017e-04, 2.898332776914590e-03, 1.557743672936717e-02, 5.385923544267934e-03, 5.091036802453178e-03, 1.670986667057646e-02, 6.048069222368302e-02, 7.684849497030732e-02, 9.633671411641264e-03, 1.028057494188629e-02, 2.981296606856095e-05, 6.313897045731797e-09, 2.935831576746288e-14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_msb86bl_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msb86bl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.150633135297185e-02, -1.196502931795063e-02, -1.264995570764403e-02, -1.368650765767223e-02, -1.527889456854007e-02, -1.774783498214839e-02, -2.146640830509432e-02, -2.580540626578217e-02, -2.181977944721628e-02, -1.459729039566330e-01, -4.182671193085754e-01, -8.335534037958264e-01, -1.284133968489227e+00, -1.612756871784457e+00, -4.894304555133766e+00, -3.156056288869278e+01, -5.337303866942894e+01, 1.459655146421902e+02, 5.771108722642011e+02, 8.332054115988004e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_msb86bl_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msb86bl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.457579317125794e-09, -1.076116760091128e-08, -1.505766966418549e-08, -2.398485569813444e-08, -4.555429552954757e-08, -1.098525306130083e-07, -3.664145822213256e-07, -1.895658716485884e-06, -1.720934433112184e-05, -7.822448342334727e-05, 2.945905619658176e-04, 5.474756128648920e-03, -6.577665512389892e-02, 2.736964885192930e-01, 3.814973205936298e+00, 5.012892600753360e+02, 1.565097186086857e+04, -1.505515096851294e+06, -5.557792193950191e+09, -8.181421499646569e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_msb86bl_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msb86bl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.154174204551663e-05, 3.551268562543924e-05, 4.209990968864764e-05, 5.372940057877076e-05, 7.617900432083518e-05, 1.254235219000284e-04, 2.549983400901021e-04, 6.950651784655007e-04, 2.770297847241956e-03, 6.714287401150243e-03, 3.204979695314059e-03, 2.853962937323666e-02, 3.386583987346693e-01, -3.574430705130092e-02, -5.668632563033600e-01, -4.602277826227565e+01, -1.622877792072267e+02, -3.652685902672061e+01, -1.726260555837829e+00, -1.239008678892612e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_msb86bl_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msb86bl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.502021441323797e-13, 8.295881082914423e-13, 1.177228302486849e-12, 1.945617577219085e-12, 3.999281325229232e-12, 1.122374060011887e-11, 4.906160183127345e-11, 4.018711628592166e-10, 7.900041574981876e-09, 2.182646899196156e-07, -1.271316268746962e-06, 1.393025205977136e-05, -1.792296496904350e-02, 2.737780797628828e-02, -4.701595556120754e+00, -9.573621798170741e+03, -3.952646285556422e+06, 7.194277540069050e+09, 3.975580773289066e+15, 4.611993521226128e+23]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_msb86bl_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msb86bl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.161211631405585e-10, -1.099453168008942e-09, -1.428799463790037e-09, -2.081179913684345e-09, -3.568818603554217e-09, -7.724674243702731e-09, -2.328530274548049e-08, -1.121863638357894e-07, -1.035442551806311e-06, -9.284394313326017e-06, 4.081997783240374e-05, 5.683895338833762e-04, 6.167770336921311e-02, -1.584725067225716e-02, 3.322915160713325e+00, 9.247155843220108e+02, 3.872918901674882e+04, 2.540234153505503e+05, 1.349905701844243e+06, 7.243118381642518e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_msb86bl_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msb86bl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.312155543030006e-06, 1.481191127843928e-06, 1.762748088846660e-06, 2.262829441074520e-06, 3.236885539164610e-06, 5.402965368897971e-06, 1.122888644447752e-05, 3.180608516471812e-05, 1.376967656436119e-04, 4.052759262450590e-04, -6.177024585629217e-04, -3.342185346419455e-03, -2.063838637515265e-01, -9.344612417546364e-03, -2.073610490159322e+00, -8.663635899354469e+01, -3.179584303618071e+02, -6.671000588588183e+01, -3.114032386115510e+00, -2.247732126306631e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
