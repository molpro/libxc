
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_mn15_l_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15_l", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.032552149370415e-01, -2.123101549703760e-01, -2.235206704234278e-01, -2.356877168917024e-01, -2.446493186213052e-01, -2.399903248374471e-01, -2.020169566575464e-01, -1.111999155290421e-01, 8.377812642190905e-03, 8.180133026314561e-02, 7.572163194824198e-02, -1.100443673420834e-01, -5.281275638732983e-02, -3.783139659767108e-02, 6.995900857173296e-03, 3.703980731209059e-02, -8.158676409248234e-03, -2.662330429778997e-02, -8.840259313179322e-03, -1.207807478268338e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_mn15_l_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.893532198392943e-01, 2.427093225401744e-01, 1.725494749225927e-01, 6.751777931522897e-02, -8.515498491014679e-02, -2.878506213266169e-01, -4.953346511700957e-01, -5.605930383968684e-01, -3.469338308440846e-01, -1.347087510265575e-01, -9.902351321391918e-02, -8.500663366974981e-02, -1.229259995296195e-01, -1.788852662319406e-01, -1.085996110219935e-01, -4.999312161719271e-02, 3.827488911338655e-02, -2.610352680641626e-02, -1.125151262990655e-02, -1.588598366057213e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn15_l_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.348830007719157e-06, -1.513578046453801e-06, -1.752873903711167e-06, -2.094972395181835e-06, -2.558287714624972e-06, -3.076455766625455e-06, -3.187593407190164e-06, -8.385761881843201e-07, 1.221885137174751e-05, 7.646892813050256e-05, 7.381542607869432e-04, 1.951779614672739e-02, 5.837938354755950e-03, 1.223125718193207e-02, 1.336229902243642e-01, 8.933446809877419e-01, 2.022839859675501e+00, 9.990240745629836e-01, 1.265914604224642e-01, 3.160047110930409e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn15_l_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.549712952869226e-03, -8.510038788516817e-03, -6.932659382010221e-03, -4.539365328580346e-03, -9.867364900631084e-04, 3.891874592494248e-03, 9.209370993956707e-03, 1.148758942671267e-02, 6.743321937891871e-03, 1.102043946650642e-03, -2.617975825993256e-03, -2.320779959648603e-02, 1.950342673179168e-02, 6.147519180348195e-02, -1.140700734339675e-02, -4.591960835292310e-02, -5.928349838126502e-02, -6.430247386540093e-03, -1.029271198685233e-04, -1.953721083126505e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn15_l_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.007498445134055e-02, 1.143240201561274e-02, 1.341798900690181e-02, 1.624921114923452e-02, 1.994186050449090e-02, 2.335197317720365e-02, 2.115397926980278e-02, -3.654584115806980e-04, -4.290491561704553e-02, -4.911683353212500e-02, -3.257499035532685e-01, 7.408761305317794e-01, -5.666139109954808e-01, -7.037371545124865e-01, 1.778221880681806e-01, -3.551036949677073e+01, -1.905699979295575e+00, 3.673293120090328e+02, -9.911734083086369e+03, -1.287626993929434e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn15_l_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.280513319641662e-08, 1.072985307938634e-08, 6.534805791093994e-09, -2.612396531485490e-09, -2.432998646856177e-08, -8.082378291382372e-08, -2.403755603637432e-07, -6.963143016522418e-07, -1.479446637682163e-06, 1.278620944034248e-05, 8.440443695147614e-04, -4.022010182581134e-02, -1.558546393686870e-01, -4.357640695875975e-01, -9.390125639172853e-01, 1.963833075587414e+02, 1.097941553278588e+04, 1.960134621977870e+05, 2.894501590197049e+06, 5.414509202588468e+07]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_mn15_l_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.706341429258363e-04, -2.988406367456216e-04, -3.393694126038340e-04, -3.952568182980782e-04, -4.625501879487720e-04, -5.049291070014910e-04, -3.773429906813045e-04, 2.661282407535701e-04, 1.340394786142860e-03, 4.432769954715193e-04, 5.438583081996154e-04, -2.380667896932750e-02, 3.670946217660387e-01, 9.964486446389577e-01, 3.705824366481105e-01, -1.880908693014225e-01, -1.132875075902363e+02, -5.563630712154486e+02, -1.061490648791121e+03, -1.509024529898432e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn15_l_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.862406139738268e-13, 2.381356282026975e-13, 3.327779220159470e-13, 5.211737316031815e-13, 9.391659181483075e-13, 1.978162742364126e-12, 4.601667238272944e-12, 3.905302089208153e-12, -3.121688863980085e-10, -2.244002776419137e-08, -5.768001154352093e-06, -4.248723192077136e-03, -4.638226240907777e-03, -3.609175319809601e-02, -5.581114929671319e+00, -2.169826835342792e+03, -1.021073066473837e+06, -5.536349758770571e+08, -9.648465725471575e+11, -1.384457254263138e+16]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_mn15_l_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.405228331103944e-10, -4.181635136135492e-10, -3.631912430770717e-10, -2.233877247724841e-10, 1.522679657025590e-10, 1.240338120264889e-09, 4.692786968426097e-09, 1.689742188285255e-08, 7.060488136863307e-08, 5.635744664594946e-07, 1.762871921796861e-05, 3.950877635132681e-03, 5.891450602072074e-02, 2.609603109806128e-01, 2.318695417957795e+00, 5.769982156605590e+01, 5.712042456458430e+02, 1.255515595597192e+03, 9.469012066211445e+02, 2.439870427834989e+02]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_mn15_l_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.307696853030858e-06, 8.868097904545919e-06, 9.628118690319261e-06, 1.056075476620018e-05, 1.134911222118906e-05, 1.062401979216296e-05, 3.877897591683900e-06, -1.857684491657376e-05, -5.391425389257771e-05, -4.964911969392017e-05, -1.887886363696107e-04, -1.647131199491639e-04, -2.151912177282214e-01, -1.058949788592250e+00, -1.627609730672761e+00, -5.579617424813152e+00, 1.029393874288324e+02, 5.587205335043025e+02, 1.152785427861151e+03, 1.731844659835289e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
