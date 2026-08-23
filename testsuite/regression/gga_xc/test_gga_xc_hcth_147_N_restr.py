
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_hcth_147_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_147", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.524027168310654e+00, -4.432394995255101e+00, -4.304115911778900e+00, -4.126681307033421e+00, -3.885501414610861e+00, -3.565914114776658e+00, -3.158048636190177e+00, -2.666402494574738e+00, -2.125278061850330e+00, -1.604021980365787e+00, -1.102845015611256e+00, -7.206572985700331e-01, -6.284614429076115e-01, -5.173166498883653e-01, -3.781623046767846e-01, -2.546322011752027e-01, -1.374551120844249e-01, -4.190259596174172e-02, -7.327766540028726e-03, -7.494219682483342e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_hcth_147_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_147", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.115344762176694e+00, -5.988209150656284e+00, -5.809613471466025e+00, -5.561259381822782e+00, -5.220776020062737e+00, -4.763019883140680e+00, -4.163339907891374e+00, -3.403331635492517e+00, -2.486578003989043e+00, -1.531633196467439e+00, -9.458815254479802e-01, -9.231433955371597e-01, -8.270221269641089e-01, -6.458366086675288e-01, -4.165281896876570e-01, -2.217582949103892e-01, -1.545382394870659e-01, -5.695484189881603e-02, -9.961032508155245e-03, -1.001821742557255e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_147_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_147", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.106969142162872e-06, 1.123573562501626e-06, 1.137651933780964e-06, 1.131539980047152e-06, 1.045341627622748e-06, 6.667280219603687e-07, -8.461838295530198e-07, -7.422912507996701e-06, -4.103883445778946e-05, -2.370129346572345e-04, -1.361003293702836e-03, -2.121072690884711e-03, -9.728526613776525e-04, -1.254641891844937e-02, -7.392287742564534e-02, -6.131824007984897e-01, -2.159035713225741e+00, -1.762614229120269e+00, 3.308886362286439e+00, 7.522068766593894e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_147_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_147", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.285577397880792e-02, -1.351006668998238e-02, -1.451996169695114e-02, -1.613135738948104e-02, -1.883521683355275e-02, -2.373647348500237e-02, -3.372942820851813e-02, -5.774732122167656e-02, -1.254722289463617e-01, -2.982419018179679e-01, -6.312845514627309e-01, -6.207736317137726e-01, -8.099632717111590e-01, -1.259538124693341e+00, -4.072626236914697e+00, -3.351107271527896e+00, 2.654595369887370e+01, -5.633757852814815e+02, -1.275581550368148e+04, -8.767785856940694e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_147_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_147", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.622480657013786e-08, 1.943204403331221e-08, 2.513142606161225e-08, 3.623961093034476e-08, 6.095471492313225e-08, 1.273437295734500e-07, 3.590987827254861e-07, 1.499574701281663e-06, 9.754499228118150e-06, 8.744667109668432e-05, 1.213503835329272e-03, 1.044304162041671e-02, 5.631270632030478e-02, 1.012444121310707e-01, 2.072632625163327e+00, -8.663447578862604e+00, -5.036449237327757e+03, -2.100513229247352e+05, 4.329065664974694e+07, 7.716369857154651e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_147_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_147", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.529203246712919e-13, -3.118585533767942e-13, -4.215270868495701e-13, -6.504239702821126e-13, -1.215151080145571e-12, -2.993225225950466e-12, -1.095236436906913e-11, -6.878879738293212e-11, -8.160523892097231e-10, -1.397279784739337e-08, -3.007735001957484e-07, -3.753588833223898e-04, -1.816422532673414e-02, -3.684314832907216e-03, -5.972023341166462e-01, 3.926455498929550e+02, 4.985970758457177e+05, 5.448498337769951e+08, -1.685438182320512e+13, -2.197017472106960e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
