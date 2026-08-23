
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_edmgga_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_edmgga", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.384346812988559e+00, -3.371978599961615e+00, -3.361104538671570e+00, -3.352110113838448e+00, -3.327574577943531e+00, -3.231337279809770e+00, -3.003860083246993e+00, -2.643185261497989e+00, -2.194090052003064e+00, -1.715992769375617e+00, -1.202980398907661e+00, -6.675164229232721e-01, -5.308357876522075e-01, -4.676591854455978e-01, -3.651254635865205e-01, -2.617194745436224e-01, -1.735402043273899e-01, -1.079991986282106e-01, -6.832034291723958e-02, -4.605813122920926e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_edmgga_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_edmgga", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.717435948533070e+00, -4.811537947462037e+00, -4.960161337699872e+00, -5.137223333500828e+00, -5.173311667258718e+00, -4.838533323240052e+00, -4.204067459007034e+00, -3.423387479038400e+00, -2.542562390296377e+00, -1.705613188669960e+00, -1.115126643283205e+00, -9.141114085858772e-01, -8.213152239857584e-01, -6.349806274827378e-01, -3.920269186019117e-01, -2.187037435670978e-01, -1.252952684871806e-01, -6.504952009019944e-02, -3.196088686891648e-02, -1.752028566676974e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_edmgga_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_edmgga", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.352939809459775e-07, -3.335589695797924e-07, -8.523409846208653e-07, -2.164625249808459e-06, -4.926398952457666e-06, -9.158865281427292e-06, -1.557591140753810e-05, -3.100732236928732e-05, -7.992304880725919e-05, -2.646318773531272e-04, -1.230541737609018e-03, -6.934255851775860e-03, -1.096987827445651e-02, -2.868184616959457e-02, -1.165643955293351e-01, -6.369186643698579e-01, -5.693246539661504e+00, -1.298526634831275e+02, -1.113922533874401e+04, -6.181788382325557e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_edmgga_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_edmgga", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.845869893819098e-05, -1.123771979246843e-04, -2.629784136349886e-04, -5.886273579677897e-04, -1.117629645511182e-03, -1.602722628008091e-03, -1.880185505397742e-03, -2.203782653820482e-03, -2.679285850322307e-03, -3.119865722126979e-03, -3.953913060945277e-03, -8.589224416204209e-03, -9.021064411106961e-03, -1.225239165386513e-02, -1.561926132019021e-02, -1.482908480349027e-02, -1.118209839351688e-02, -8.358647893041525e-03, -6.363084152178391e-03, -4.773326496335762e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_edmgga_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_edmgga", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.938347957527639e-04, 4.495087916987373e-04, 1.051913654539955e-03, 2.354509431871159e-03, 4.470518582044728e-03, 6.410890512032366e-03, 7.520742021590969e-03, 8.815130615281929e-03, 1.071714340128923e-02, 1.247946288850792e-02, 1.581565224378111e-02, 3.435689766481684e-02, 3.608425764442785e-02, 4.900956661546053e-02, 6.247704528076083e-02, 5.931633921396109e-02, 4.472839357406752e-02, 3.343459157216610e-02, 2.545233660871356e-02, 1.909330598534305e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_edmgga_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_edmgga", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.270458263654718e-02, -1.604804506410097e-02, -2.121606069747480e-02, -2.664492070678582e-02, -2.651542465679447e-02, -2.327665309061897e-02, -2.987005593409681e-02, -4.822816287799541e-02, -9.067399070321751e-02, -1.624757260339200e-01, -2.933531642676472e-01, -6.180369789178171e-01, -8.746529258431609e-01, -1.334073443500196e+00, -3.565317243741227e+00, -4.689380051346530e+00, -4.621287848147492e-01, 1.029869367178309e+02, 1.823203709296735e+04, 1.190959487395193e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_edmgga_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_edmgga", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.788144139373155e-09, -4.735818495635866e-09, -1.238224281947789e-08, -2.600837351493630e-08, -1.535265271512242e-08, 1.013434534821111e-07, 3.481781459149312e-07, 1.148174307995681e-06, 5.252521589842766e-06, 2.420233943588496e-05, 1.980809624103464e-04, 1.507667417262549e-02, 1.344113814371967e-02, 1.802455531388448e-01, 1.455144178261018e+00, -2.939974359589123e+00, -1.049394301963731e+03, -1.877577978887552e+05, 1.555908686114046e+09, 1.537707918443372e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_edmgga_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_edmgga", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.110535458160019e-07, -2.262631959034090e-06, -5.525057420690850e-06, -1.140171728733967e-05, -1.333578415455687e-05, -5.834980891400157e-07, 1.087714654132983e-05, 1.958951938072062e-05, 1.623585851951660e-05, -2.439313527426735e-04, -1.824619972630426e-03, 4.806446458758684e-03, -1.088645496074300e-02, 1.963410961073685e-02, -3.814406115379642e-02, -1.342287401782507e+00, -1.344760711266190e+01, -2.717913426060410e+02, -2.138966554191726e+04, -1.117622101955364e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_edmgga_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_edmgga", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.644214183264008e-06, 9.050527836136361e-06, 2.210022968276340e-05, 4.560686914935868e-05, 5.334313661822749e-05, 2.333992356560063e-06, -4.350858616531930e-05, -7.835807752288247e-05, -6.494343407806641e-05, 9.757254109706940e-04, 7.298479890521705e-03, -1.922578583503474e-02, 4.354581984297201e-02, -7.853643844294740e-02, 1.525762446151857e-01, 5.369149607130030e+00, 5.379042845064759e+01, 1.087165370424164e+03, 8.555866216766903e+04, 4.470488407821456e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_edmgga_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_edmgga", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.845141791632197e-15, -7.796566355034651e-15, -3.516454590288610e-14, -1.531238739182779e-13, -4.899976043435653e-13, -6.604931149267059e-13, 3.199295093197316e-13, 4.680385746283400e-12, 2.306711201597306e-10, 1.620159655690531e-08, 2.072120505017375e-06, 4.266898169747042e-05, -2.138373822159670e-03, 3.011411869718515e-03, 1.063017801973478e+00, 3.710814788907225e+02, 4.711192522070776e+05, 9.156638397452961e+09, 9.502634508862860e+15, 2.790320208288196e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_edmgga_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_edmgga", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.608806242066405e-13, -2.626690811272199e-12, -1.084955043180185e-11, -4.163903260127104e-11, -1.111635200739527e-10, -1.155806127079110e-10, 3.861904516745370e-11, 3.326489400795384e-10, 7.732861515485988e-09, 1.910080004238085e-07, 6.658030425331166e-06, 5.285260123717885e-05, -1.758488791042040e-03, 1.286423385744387e-03, 1.424410323721829e-01, 8.639719680564490e+00, 9.253247328321136e+02, 5.894150662389627e+05, 5.428210778444178e+09, 2.154572198162595e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_edmgga_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_edmgga", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.643522496826562e-12, 1.050676324508879e-11, 4.339820172720740e-11, 1.665561304050841e-10, 4.446540802958109e-10, 4.623224508316441e-10, -1.544761806698148e-10, -1.330595760318154e-09, -3.093144606194395e-08, -7.640320016952340e-07, -2.663212170132466e-05, -2.114104049487154e-04, 7.033955164168160e-03, -5.145693542977549e-03, -5.697641294887315e-01, -3.455887872225796e+01, -3.701298931328454e+03, -2.357660264955851e+06, -2.171284311377671e+10, -8.618288792650380e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_edmgga_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_edmgga", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.367098297987179e-10, -8.849414349646919e-10, -3.347483709793920e-09, -1.132291778939086e-08, -2.521916043199195e-08, -2.022561285202578e-08, 4.661747685660722e-09, 2.364234986911271e-08, 2.592311823702815e-07, 2.251880306842458e-06, 2.139323897297363e-05, 6.546670078376495e-05, -1.446090854730637e-03, 5.495379572720948e-04, 1.908664903408595e-02, 2.011546261534519e-01, 1.817429148097037e+00, 3.794079281389090e+01, 3.100768763413542e+03, 1.663673345914331e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_edmgga_N_restr_1_v2lapltau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_edmgga", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapltau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapltau"])
    tgt = out["v2lapltau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.468393191948717e-10, 3.539765739858768e-09, 1.338993483917568e-08, 4.529167115756344e-08, 1.008766417279678e-07, 8.090245140810313e-08, -1.864699074264289e-08, -9.456939947645085e-08, -1.036924729481126e-06, -9.007521227369830e-06, -8.557295589189453e-05, -2.618668031350598e-04, 5.784363418922548e-03, -2.198151829088379e-03, -7.634659613634381e-02, -8.046185046138077e-01, -7.269716592388150e+00, -1.517631712555636e+02, -1.240307505365417e+04, -6.654693383657325e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_edmgga_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_edmgga", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.787357276779487e-09, -1.415906295943507e-08, -5.355973935670272e-08, -1.811666846302538e-07, -4.035065669118712e-07, -3.236098056324125e-07, 7.458796297057155e-08, 3.782775979058034e-07, 4.147698917924505e-06, 3.603008490947932e-05, 3.422918235675781e-04, 1.047467212540239e-03, -2.313745367569019e-02, 8.792607316353517e-03, 3.053863845453753e-01, 3.218474018455231e+00, 2.907886636955260e+01, 6.070526850222544e+02, 4.961230021461668e+04, 2.661877353462930e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
