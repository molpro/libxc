
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_rppscan_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rppscan", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.656284922449114e-02, -2.651925472851802e-02, -2.645493421573910e-02, -2.635903041895383e-02, -2.621398597006086e-02, -2.599064212426140e-02, -2.564037337454426e-02, -2.509129123214596e-02, -2.434192239703566e-02, -2.498420798935301e-02, -3.138925144208364e-02, -5.593276643131138e-02, -4.748546328065137e-02, -2.993052463457727e-02, -2.402879692414392e-02, -1.824722465283280e-02, -9.815656101905563e-03, -3.466918419907014e-03, -5.764410752534624e-04, -3.002387826536430e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_rppscan_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rppscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.641769129816269e-02, -3.660278580719442e-02, -3.687315882275324e-02, -3.727072215572318e-02, -3.786084107503603e-02, -3.874876838100954e-02, -4.011355020114311e-02, -4.230836291724104e-02, -4.650071361326424e-02, -6.073156399974497e-02, -6.100449543575397e-02, -8.206269072826396e-02, -3.207255378481391e-02, -4.049019174780814e-02, -4.906143044780007e-02, -5.008051991209522e-02, -2.463956293819854e-02, -7.412944749109353e-03, -1.265500639704005e-03, -9.370305175679290e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rppscan_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rppscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.371317572068957e-07, 2.581495216752507e-07, 2.915775622925394e-07, 3.471117412127848e-07, 4.452968521691206e-07, 6.350233099725076e-07, 1.051463884188930e-06, 2.154400275371845e-06, 6.163769349963724e-06, 3.584106571231418e-05, 9.873399182472122e-05, 3.273217893828792e-03, 1.205192921807802e-02, 1.792618827422307e-02, 6.474475596746293e-02, 4.038527702248284e-01, 1.864313475013815e+00, 1.141995140959580e+01, 2.213287613176129e+02, 2.370041807788318e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rppscan_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rppscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.047365538542638e-04, -3.115889795604969e-04, -3.216126688136240e-04, -3.363727897701068e-04, -3.583047327061486e-04, -3.913113225768576e-04, -4.420528962103483e-04, -5.244487525497275e-04, -6.930706360794291e-04, -1.409252800400386e-03, -2.628287174819266e-04, -1.630299783251347e-03, -2.070472963162495e-02, -2.314987777421467e-02, -2.812169724462564e-02, -3.082703469355916e-02, -1.068519226395689e-02, -1.516187217236462e-03, -2.571906848292480e-04, -5.908372876585980e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rppscan_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rppscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.001496308303810e-05, 4.154224885135488e-05, 4.359169285822545e-05, 4.606768933401576e-05, 4.799695619356784e-05, 4.452412728361972e-05, 1.197992548112512e-05, -1.843015176674626e-04, -1.535371398812087e-03, -6.178091894177428e-03, -3.239431354830372e-02, 5.138199795145802e-02, 1.911842892087408e-01, 1.553481430403088e-01, 2.025840172146852e-01, 7.789142602806702e+00, 7.864585147970099e+01, 6.636003317010501e+02, 2.703168138311103e+04, 9.926294733429139e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rppscan_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rppscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.109795411483623e-10, 2.910299203548269e-10, 4.439096675364478e-10, 7.702187827669337e-10, 1.581101922874588e-09, 4.063821898765321e-09, 1.422804603660669e-08, 7.744157318872430e-08, 8.097398701587319e-07, 1.236541705349113e-05, 6.378426151052765e-05, 2.608794266589620e-03, -1.809635276757386e-02, -3.275960321366835e-02, 4.429700580980639e-01, -1.436864781208972e+02, -1.787672219424593e+04, -5.032984716109782e+06, -2.184664862213492e+10, -5.694467819547980e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rppscan_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rppscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.515602490460664e-06, -1.701961769972992e-06, -2.008893969639324e-06, -2.545008732283707e-06, -3.563675234108277e-06, -5.748238648593618e-06, -1.133751132222450e-05, -3.004565121205642e-05, -1.262880279912715e-04, -6.491806667227952e-04, 2.213213494502942e-04, -8.491264672741659e-03, -5.957606329525981e-02, -4.799468050311355e-02, -4.555585791882339e-01, 1.272130140437682e+01, 1.404813198825427e+02, 1.335832090488520e+03, 5.014118530255699e+04, 1.738695529211152e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rppscan_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rppscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.280875743716604e-14, -5.383804882452536e-14, -7.483963450374267e-14, -1.201025324927237e-13, -2.367963394693626e-13, -6.270769289584637e-13, -2.538521958798607e-12, -1.913334723607408e-11, -3.729258083860136e-10, -1.990002638202824e-08, -1.575570548754031e-06, -8.964453290521986e-04, -1.021524526685258e-02, -8.392279358368022e-02, -3.404769457663471e+00, 2.662840681018435e+03, 3.738297838937689e+06, 3.304927221943993e+10, 1.630689961244501e+16, 3.235261149478515e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rppscan_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rppscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.926043754930285e-11, 4.663304033281749e-11, 5.971985202377593e-11, 8.520847064443896e-11, 1.419878213470952e-10, 2.957848783620166e-10, 8.517260124301409e-10, 3.974358679235633e-09, 3.948384130673258e-08, 7.100266024023174e-07, 1.346957880006309e-05, 5.439800896819092e-05, 8.513172019777041e-04, 7.551545863014762e-02, 1.031874670112841e+00, -2.784010702917416e+02, -3.101231374355235e+04, -8.869284759676397e+06, -3.765256666693837e+10, -9.950554860385200e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rppscan_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rppscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.583462344748376e-08, -2.929859836303202e-08, -3.510256889856377e-08, -4.550288154570991e-08, -6.604199172881686e-08, -1.127822612037021e-07, -2.441138677394210e-07, -7.558771294705640e-07, -4.098691234414159e-06, -2.518387776965285e-05, -1.626877652302621e-04, 8.110245143760121e-04, 3.351473631802411e-02, -5.563622054057199e-02, -2.496783182503560e-01, 2.783517039540832e+01, 2.491809515767684e+02, 2.289903693538831e+03, 8.515369958195159e+04, 3.052797549358505e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
