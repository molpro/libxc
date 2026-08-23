
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_mpwkcis1k_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpwkcis1k", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.600323726419984e+00, -2.551651545996640e+00, -2.483483065350430e+00, -2.389121987834059e+00, -2.260688479257130e+00, -2.090058641996498e+00, -1.871076038378688e+00, -1.603505118937300e+00, -1.298171057611939e+00, -9.785193781328574e-01, -6.652095809573098e-01, -4.407703804425778e-01, -3.826267765906657e-01, -3.132208634620526e-01, -2.284922403915396e-01, -1.478033968454474e-01, -8.380178799501135e-02, -2.177907630331167e-02, -4.419120449108829e-04, -1.470917532844178e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_mpwkcis1k_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpwkcis1k", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.275182352082389e+00, -3.207475849554890e+00, -3.112566150261170e+00, -2.981020143571523e+00, -2.801633525128789e+00, -2.562641394423032e+00, -2.254710987930506e+00, -1.876735849926389e+00, -1.445583696933062e+00, -1.011198862950806e+00, -6.694185248730677e-01, -5.503435149596895e-01, -4.953534116114330e-01, -3.900129140511991e-01, -2.621095780619717e-01, -1.488859392247052e-01, -8.378642820076135e-02, -5.670207298035311e-02, -1.632713115019811e-03, -5.463299386069901e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpwkcis1k_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpwkcis1k", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.379405456346048e-06, -1.512317475311013e-06, -1.723371756262754e-06, -2.072938581018133e-06, -2.687367794403818e-06, -3.860891552543543e-06, -6.374940357999377e-06, -1.267009781178344e-05, -3.204094069268025e-05, -1.094295310828529e-04, -5.405833111131622e-04, -1.733311478488780e-03, 1.592536511097517e-03, -1.645935397131216e-03, -2.388730127433401e-02, -2.140733405209367e-01, -1.696679571244784e+00, 6.342886782976406e+01, 2.907163741911766e+02, 8.077498604918715e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpwkcis1k_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpwkcis1k", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.212282073809705e-03, -1.193879987402960e-03, -1.167587764549651e-03, -1.130100786370784e-03, -1.076801465368222e-03, -1.001371110858054e-03, -8.957084035889734e-04, -7.514884474761306e-04, -5.670819389633522e-04, -3.667093138650232e-04, -2.392896474372746e-04, -3.792567337109326e-04, -3.116279924917580e-03, -9.069428552140622e-03, -7.607986839807014e-03, -3.996328657563519e-03, -1.338184407363444e-03, -2.179104887217504e-04, -1.169362396199223e-05, -1.639250050361012e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpwkcis1k_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpwkcis1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.361914310085088e-03, -7.695416186369948e-03, -8.201261823124143e-03, -8.986395606939300e-03, -1.024571687389568e-02, -1.236175092138991e-02, -1.615484977876227e-02, -2.356224284144680e-02, -3.949875298081695e-02, -7.599595359133704e-02, -1.758065603946581e-01, -3.462450982869206e-01, -4.250212341157347e-01, -7.707572178830004e-01, -1.826992819792690e+00, -5.141498759660578e+00, 4.099810608782384e+01, -1.105108891053932e+03, -1.531440821863609e+04, -3.818803050094176e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpwkcis1k_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpwkcis1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.834435671902458e-08, 2.077978144232728e-08, 2.484444074938851e-08, 3.207940239399313e-08, 4.619355503657144e-08, 7.753904278713640e-08, 1.609762315422395e-07, 4.451097787344776e-07, 1.767445397946900e-06, 1.041024537388752e-05, 1.472932637233559e-04, 6.827990150213458e-03, 2.771530113431664e-02, 1.111393380485010e-01, 8.880820687740045e-01, 1.279181618913443e+01, -4.216413583432844e+03, 1.270599784412680e+06, 3.725432741235538e+09, 7.645389799939772e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpwkcis1k_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpwkcis1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.083777918948022e-06, -7.518214679726399e-06, -8.184180415644833e-06, -9.232227692889038e-06, -1.094206817765137e-05, -1.386954538192681e-05, -1.920474588389911e-05, -2.970842813374442e-05, -5.239509300724296e-05, -1.073675378593708e-04, -2.674615987251520e-04, -5.907755294574620e-04, -4.757605187253825e-03, -4.338019459660556e-02, -1.646790717508913e-01, -6.518148184081476e-01, -3.006369529518329e+00, -1.748812828687980e+01, -1.086054516865912e+02, -1.131666376155758e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpwkcis1k_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpwkcis1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.207032145430089e-14, -6.037204243129027e-14, -7.428454495677492e-14, -9.879552822022027e-14, -1.437209929578343e-13, -2.191378576442993e-13, -1.811051548552180e-13, 3.329931215923714e-12, 1.056269671835648e-10, 5.756278117343839e-09, 7.853775578850679e-07, -2.273000268946063e-04, -8.287376933713375e-03, -2.563487581864502e-02, -2.804746050823111e-01, 6.192601117854065e+01, 4.351500164558490e+05, -8.886215516459770e+09, -1.393593514303706e+15, -2.264979183833967e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpwkcis1k_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpwkcis1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.195801757431016e-10, -1.321663755215496e-10, -1.525507689573963e-10, -1.872928619950413e-10, -2.509485319067628e-10, -3.801134854139625e-10, -6.825316793634439e-10, -1.547251503435866e-09, -4.820644557003536e-09, -2.384433120639927e-08, -3.541907137248054e-07, -8.718779995627508e-05, -6.006949481289279e-03, -2.722259861867297e-02, -1.382869256950811e-01, -1.538953189046757e+00, -4.691442157935040e+01, -1.406704655084364e+03, -1.748679421087998e+05, -1.366831165592721e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpwkcis1k_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpwkcis1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.507643719897518e-07, 5.775776095695653e-07, 6.182455440861939e-07, 6.812795692211949e-07, 7.819215737231715e-07, 9.491108554322610e-07, 1.241495834828726e-06, 1.786651428694649e-06, 2.887141788975661e-06, 5.430008120666942e-06, 1.560821128467996e-05, 1.778302061044852e-04, 1.006116285130082e-02, 8.272610242354729e-02, 2.348568853762032e-01, 7.809648652625077e-01, 3.500963708325957e+00, 1.967724709848474e+01, 1.312020080542852e+02, 1.453120585148711e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
