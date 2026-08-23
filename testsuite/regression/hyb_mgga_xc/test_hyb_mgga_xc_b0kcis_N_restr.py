
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_b0kcis_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b0kcis", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.290971960579514e+00, -3.229218285254421e+00, -3.142734638263515e+00, -3.023034289599270e+00, -2.860139608508764e+00, -2.643785152681660e+00, -2.366244973137718e+00, -2.027387159648671e+00, -1.641249947591290e+00, -1.237892962485120e+00, -8.405796297836226e-01, -5.474594943077360e-01, -4.729009995904732e-01, -3.890285772180536e-01, -2.846314682925745e-01, -1.859820488323110e-01, -1.136256542310658e-01, -6.881369031240468e-02, -4.388534009147707e-02, -3.043168045728323e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_b0kcis_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b0kcis", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.136149711117353e+00, -4.050218767595007e+00, -3.929762821097359e+00, -3.762810014696503e+00, -3.535140401786224e+00, -3.231820912708951e+00, -2.840995997112987e+00, -2.361201173683121e+00, -1.813528268569064e+00, -1.260281911445195e+00, -8.266376944423198e-01, -6.785097599597719e-01, -6.097665088938221e-01, -4.790737581717951e-01, -3.194266913256879e-01, -1.765636707728900e-01, -8.009440899613374e-02, -3.290106515304986e-02, -1.211314944042898e-02, -4.978951360711202e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b0kcis_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b0kcis", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.022088261874097e-06, -2.205855914928598e-06, -2.496957480482202e-06, -2.977537431202856e-06, -3.818679951151769e-06, -5.416849254787645e-06, -8.820528351360899e-06, -1.729712880349197e-05, -4.333275633373967e-05, -1.483617232779481e-04, -7.446236437989395e-04, -2.863609060678902e-03, -6.188983794313783e-04, -6.110218561781724e-03, -4.041002661952576e-02, -3.384495233403207e-01, -4.642609440162145e+00, -1.315197788481133e+02, -1.262676620164651e+04, -7.526302331691480e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b0kcis_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b0kcis", 1)
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


def test_hyb_mgga_xc_b0kcis_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b0kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.286046899883037e-03, -9.706693186733260e-03, -1.034481663595636e-02, -1.133549122904509e-02, -1.292508903512810e-02, -1.559793980073536e-02, -2.039639994176918e-02, -2.980542669719924e-02, -5.033302547232608e-02, -9.983320856293340e-02, -2.368973399429579e-01, -4.346484391205897e-01, -5.326483670257373e-01, -9.548627712601170e-01, -2.273808127090621e+00, -7.363678834976418e+00, -2.374046545094227e+01, -8.267914524154048e+01, 1.251634816742411e+04, 7.786749622635533e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b0kcis_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b0kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.179524969315978e-08, 2.470757551841381e-08, 2.957325438326871e-08, 3.824711827252213e-08, 5.520618472706135e-08, 9.299919879238780e-08, 1.941704661673498e-07, 5.425043967794037e-07, 2.211210431532729e-06, 1.433458675445919e-05, 2.231238291917821e-04, 8.386514972105122e-03, 3.324117019040635e-02, 1.279011006419154e-01, 1.040397446047650e+00, 2.044734291352170e+01, 2.571179083758009e+02, -4.778633128496809e+05, -7.182173515065599e+09, -2.554723035136040e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b0kcis_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b0kcis", 1)
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


def test_hyb_mgga_xc_b0kcis_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b0kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.775676812576644e-14, -4.252231087269312e-14, -4.978669614507659e-14, -6.024249181989251e-14, -7.000025709519582e-14, -3.341018794448423e-14, 5.079177572763492e-13, 7.699064837969945e-12, 1.629681256485010e-10, 7.720731837191669e-09, 1.034429383322268e-06, -1.571000088782714e-04, -7.676147672703975e-03, -2.150861072236917e-02, -1.141628925906411e-01, 9.721348847202248e+01, 4.030295776117285e+05, 1.325236014527375e+10, 1.799453205189977e+16, 6.035762550235166e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b0kcis_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b0kcis", 1)
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


def test_hyb_mgga_xc_b0kcis_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b0kcis", 1)
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
