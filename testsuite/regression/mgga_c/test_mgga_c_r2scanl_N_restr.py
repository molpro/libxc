
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_r2scanl_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scanl", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.650590933772960e-02, -2.645852264957942e-02, -2.638826513599936e-02, -2.628271294704135e-02, -2.612112131063542e-02, -2.586710763481015e-02, -2.547522241524567e-02, -2.534633586806883e-02, -2.461602869329753e-02, -2.445244911198803e-02, -3.130973093232871e-02, -5.335124041501949e-02, -3.000047340087753e-02, -2.592822178142857e-02, -2.286899921986320e-02, -1.835178638987489e-02, -1.024088844335266e-02, -3.522302166908506e-03, -5.788825791291903e-04, -2.119507601688594e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_r2scanl_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scanl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.895413328703132e-02, -2.898406867373029e-02, -2.902840247071145e-02, -2.909477551723171e-02, -2.919545262469928e-02, -2.935010716007085e-02, -3.221117332941884e-02, -4.889545350060810e-02, -5.673898376816007e-02, -7.705091184662138e-02, -6.202671158824766e-02, -8.482020991433271e-02, -7.275647643360234e-02, -6.509226859377283e-02, -6.711450255237722e-02, -5.901680976833087e-02, -2.052976575019648e-02, -6.607650769481221e-03, -1.107318222796601e-03, -3.407948941715954e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scanl_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scanl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.371955355447522e-08, 2.611696784400129e-08, 2.998213781022547e-08, 3.652836645840413e-08, 4.841930190184473e-08, 7.226012328933709e-08, 1.816917728250256e-07, 1.217957970907441e-06, 4.735591905263964e-06, 3.401021332086305e-05, 8.959798931782645e-05, 3.116027492878761e-03, 7.663724815914540e-03, 1.350846607764935e-02, 6.305438980358347e-02, 4.362221762129001e-01, 8.777186541953447e-01, 5.603415748049626e+00, 9.953878018186766e+01, -8.768765532170573e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scanl_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scanl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, -4.825408234442562e-06, -4.704567053817044e-05, -9.238276975337130e-05, -2.519013921885939e-04, -2.854555067800956e-05, -3.376416338173301e-04, -3.496027075886970e-03, -3.425196239006115e-03, -5.264618312843611e-03, -6.400007720965894e-03, -5.416654480821143e-04, -3.432866507162274e-06, 2.660927721964701e-06, 6.855129384352716e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scanl_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.513226545790466e-05, 1.648709703386405e-05, 1.862743596073629e-05, 2.214141532716407e-05, 2.821908087450274e-05, 3.945716610343205e-05, -3.429046174895675e-03, -8.202151970307487e-03, -1.743947675222868e-02, -4.765643585091603e-02, -3.760535358816217e-02, -6.681738513903565e-02, -2.643382617900041e-01, -6.507868848029320e-01, -1.768951478996983e+00, 1.914316081569794e+01, -7.096757590396468e+00, -1.793346386066313e+02, -3.536659163207170e+03, -1.469626130814042e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scanl_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.751571527253743e-10, -2.031722513468020e-10, -2.512012925914131e-10, -3.399606642152380e-10, -5.222494862107825e-10, -9.553931378300322e-10, 7.095898516271828e-08, 4.174985920498108e-07, 2.714324293164211e-06, 3.443994482614047e-05, 1.406337630553106e-04, 1.102537459506436e-03, 4.116619709980792e-02, 2.219611738558507e-01, 2.830012467869483e+00, -2.746380678281535e+02, -1.215162507671695e+03, 3.181436191550668e+05, 6.646958614860991e+08, 1.645764203364979e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scanl_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, -6.489511101611755e-06, -2.140362538113148e-05, -6.598537387059431e-05, -2.972227418625834e-04, -1.240202334925904e-04, 1.193753030181314e-03, -2.333992933677605e-02, -6.861294914985556e-02, -2.876398819379417e-01, 4.780929274792727e+00, 3.149781033188023e+00, 4.340925161096472e-01, 2.163232834879651e+01, 5.927855227320816e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scanl_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.696071018165020e-16, -6.065521016810274e-16, -8.755956693540363e-16, -1.481607401061909e-15, -3.143008256067181e-15, -9.179977867408410e-15, -1.614051148747908e-12, -2.441287167090150e-11, -4.853102425745860e-10, -2.879947426394406e-08, -1.393954992526186e-06, -1.025508145765559e-03, -1.380960073556359e-02, -1.148186809913733e-01, -6.103500704524839e+00, 3.665314237883197e+03, 4.205818778644144e+05, -1.194779301179688e+09, -2.874910729891688e+14, -2.595883508207904e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scanl_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 1.377249650549056e-10, 1.144718258526906e-09, 1.065483053485406e-08, 2.150584902817934e-07, 2.183920757259164e-06, 1.240521021845228e-04, 5.552252231369118e-03, 2.779756750609250e-02, 4.738585081349623e-01, -7.073799148338091e+01, -8.886535224860997e+02, -6.379810340652570e+03, -1.435965886910798e+07, 1.979321534163127e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scanl_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, -1.207158139605893e-08, -5.458917391731145e-08, -2.378669451952201e-07, -1.630676874876909e-06, -5.108736161392796e-06, -7.352414748169723e-05, -2.226311569390921e-03, -6.867816384481405e-03, -3.717210078033120e-02, 1.320086052588919e+00, 1.434150952131855e+00, 3.440981940351452e-01, 3.805960894878358e+00, -1.526047963473971e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
