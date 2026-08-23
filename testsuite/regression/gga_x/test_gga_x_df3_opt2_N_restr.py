
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_df3_opt2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_df3_opt2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.243272484679148e+00, -4.160589292434287e+00, -4.044793373348705e+00, -3.884521135010516e+00, -3.666416034705409e+00, -3.376753366720337e+00, -3.005281397979279e+00, -2.552194041202914e+00, -2.037633322836445e+00, -1.506383532013081e+00, -1.004750339850405e+00, -6.497024405725381e-01, -5.569066155290179e-01, -4.592718174467103e-01, -3.300686432335634e-01, -2.097123011984354e-01, -1.164780239753974e-01, -4.937804861764431e-02, -1.505150440458854e-02, -3.232997938823064e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_df3_opt2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_df3_opt2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.449285484464552e+00, -5.335602399950257e+00, -5.176213567568165e+00, -4.955233599355721e+00, -4.653744836473911e+00, -4.251762442734285e+00, -3.733126715066277e+00, -3.095044832368723e+00, -2.364661974520803e+00, -1.627203570324231e+00, -1.045155008968526e+00, -8.148629498038638e-01, -7.223757366966312e-01, -5.675224094807871e-01, -3.705325470454999e-01, -2.023561881244494e-01, -1.103026335302714e-01, -5.015453541951657e-02, -1.460015317791009e-02, -2.873099013271667e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_df3_opt2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_df3_opt2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.236211744443931e-06, -2.421350724001854e-06, -2.714124576000431e-06, -3.196546450889623e-06, -4.039507814316789e-06, -5.640489198169559e-06, -9.059797818727608e-06, -1.765035286676353e-05, -4.443629360726063e-05, -1.534407720407195e-04, -7.844179784487332e-04, -4.125057458156139e-03, -7.492056919313088e-03, -1.665918166316530e-02, -6.554270795171037e-02, -4.137113462611249e-01, -3.050611694880870e+00, -3.533947104356177e+01, -1.488898563683339e+03, -3.039514438321687e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_df3_opt2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_df3_opt2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.153097530193328e-02, -1.205162598410366e-02, -1.284242337004372e-02, -1.407246671107187e-02, -1.605212491317170e-02, -1.939689412765753e-02, -2.544593730453385e-02, -3.741569682832896e-02, -6.348268288075343e-02, -1.211927535323683e-01, -2.630593544011211e-01, -5.300192296055859e-01, -6.459857941788454e-01, -1.104685037278400e+00, -2.503052353392676e+00, -4.119239013848519e+00, 2.125671647840923e+01, -1.469745307825741e+01, -1.461044320907379e+03, 4.988784519474632e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_df3_opt2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_df3_opt2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.489556457279195e-08, 1.707009742885962e-08, 2.075211274002385e-08, 2.744290139540797e-08, 4.088595209854523e-08, 7.200788648760904e-08, 1.597042881820819e-07, 4.806474708768275e-07, 2.076505546732567e-06, 1.174146900962635e-05, 1.230772499289046e-04, 7.338149962587648e-03, 2.242658168281364e-02, 8.136495370784078e-02, 6.214808830966688e-01, -8.969143724101793e+00, -3.978980721082986e+03, -1.137373134083037e+06, -4.241466807999906e+09, -6.299605070806590e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_df3_opt2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_df3_opt2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.881411969300691e-14, 2.394986969562626e-14, 3.386869475689303e-14, 5.567677770849571e-14, 1.134735898520643e-13, 3.139411905627588e-13, 1.337512322861723e-12, 1.041063455728343e-11, 1.839935083178240e-10, 9.241438672101311e-09, 1.406113333613860e-06, 1.237748900082495e-04, 6.940750082157157e-04, 8.407284833009723e-03, 6.434533409625602e-01, 3.017609929299120e+02, 5.505038333051463e+05, 5.861905039286880e+09, 3.047227990583485e+15, 3.551392894112170e+23]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
