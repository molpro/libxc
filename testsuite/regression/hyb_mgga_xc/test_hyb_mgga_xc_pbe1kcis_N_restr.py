
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_pbe1kcis_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pbe1kcis", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.405534379108531e+00, -3.341342308762444e+00, -3.251460140278960e+00, -3.127091057678730e+00, -2.957919074362329e+00, -2.733394045224354e+00, -2.445736018577489e+00, -2.095264591311362e+00, -1.696961842714920e+00, -1.280168897922729e+00, -8.678527882535927e-01, -5.646740289321817e-01, -4.881852001893539e-01, -4.011782856374635e-01, -2.938398935243009e-01, -1.894672600142715e-01, -9.800595430600303e-02, -3.341041872065911e-02, -6.876923843998628e-03, -7.572025282773211e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_pbe1kcis_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pbe1kcis", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.297872793539447e+00, -4.207968741971970e+00, -4.081902060252630e+00, -3.907090538755328e+00, -3.668546806218080e+00, -3.350465807079992e+00, -2.940273912545606e+00, -2.436958885126919e+00, -1.866983826966445e+00, -1.309715035429204e+00, -8.718295664520014e-01, -7.009395873278599e-01, -6.317028049373997e-01, -4.938848738363248e-01, -3.283496890097185e-01, -1.977708928122494e-01, -1.171577544700022e-01, -4.526126653500460e-02, -9.250794558072494e-03, -1.010794642793719e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pbe1kcis_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pbe1kcis", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.925807645037288e-06, -2.111547512993007e-06, -2.407190574802332e-06, -2.898551255242621e-06, -3.766488827394374e-06, -5.435614368449030e-06, -9.042467731749297e-06, -1.814246903808715e-05, -4.596057969265729e-05, -1.511523284146433e-04, -7.211116199503511e-04, -2.905567039234400e-03, -4.032044519579336e-05, -6.626079237198825e-03, -4.357122035174690e-02, -2.497729217767294e-01, -7.183152262667150e-01, 2.701900091268216e+00, 2.881319955526608e+01, 3.191651112518271e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pbe1kcis_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pbe1kcis", 1)
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


def test_hyb_mgga_xc_pbe1kcis_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pbe1kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.855519937580456e-03, -1.031476622837649e-02, -1.101278005865264e-02, -1.209918974723049e-02, -1.384773484409204e-02, -1.679544161612678e-02, -2.207551661904640e-02, -3.217863010746938e-02, -5.174041191440125e-02, -7.947878789177454e-02, -1.411228535554371e-01, -4.682299245494277e-01, -5.593430011829346e-01, -1.028395549834335e+00, -2.164007554537981e+00, -1.236176233774137e+00, 4.424582784060249e+00, -5.279627364671944e+02, -1.184427642048937e+04, -8.843117690388361e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pbe1kcis_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pbe1kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.467575779499505e-08, 2.808976870490584e-08, 3.381922205523384e-08, 4.409430465931607e-08, 6.433456901947734e-08, 1.097804935615134e-07, 2.315726224852381e-07, 6.378185250867275e-07, 2.254656480093242e-06, 5.018974719548839e-06, -5.694031624944409e-05, 1.011250088499191e-02, 3.655177730778152e-02, 1.466327813322253e-01, 8.951058573556900e-01, -1.561572671187211e+01, -2.504977393893717e+03, 2.370716254784685e+05, 3.599515559338620e+08, 3.023689263450537e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pbe1kcis_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pbe1kcis", 1)
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


def test_hyb_mgga_xc_pbe1kcis_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pbe1kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.635548239063084e-14, -8.971110954013262e-14, -1.126421340915929e-13, -1.546830263597022e-13, -2.375925165885241e-13, -4.047226663646682e-13, -5.670005260115605e-13, 4.053147620159661e-12, 1.838610897263138e-10, 1.172339823813850e-08, 1.728393592644972e-06, -2.883502441491957e-04, -9.603099177545796e-03, -2.727149953607153e-02, 8.201809621645362e-02, 2.359370192968899e+02, 2.290864923661999e+05, -8.883684702060950e+08, -1.443998807304001e+14, -9.310283982651401e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pbe1kcis_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pbe1kcis", 1)
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


def test_hyb_mgga_xc_pbe1kcis_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pbe1kcis", 1)
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
