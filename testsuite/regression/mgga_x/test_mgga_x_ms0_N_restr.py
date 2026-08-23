
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ms0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.784322632096693e+00, -4.688431203072051e+00, -4.554062541842630e+00, -4.367925787270469e+00, -4.114287513591471e+00, -3.776717642509275e+00, -3.342279456266929e+00, -2.809156320610615e+00, -2.196684562860018e+00, -1.535745340737707e+00, -9.477727079184382e-01, -5.987530294876924e-01, -5.602878820075640e-01, -4.842152057892223e-01, -3.355804746447085e-01, -1.948962915477719e-01, -9.159673487040572e-02, -3.018607573256740e-02, -6.273212892768176e-03, -6.937442952067226e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ms0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.325527727078970e+00, -6.196665095560712e+00, -6.016015510979534e+00, -5.765589151086480e+00, -5.423933035621333e+00, -4.968190968334976e+00, -4.378811628799620e+00, -3.645969409274037e+00, -2.762029835247975e+00, -1.643113433604876e+00, -1.077633831352358e+00, -8.054454262304309e-01, -7.768218053873858e-01, -6.341202400506168e-01, -3.763134071000678e-01, -2.238651177462090e-01, -1.126640659084139e-01, -3.992836583889436e-02, -8.361241816443684e-03, -9.249880770113956e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms0_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.070887338517290e-07, -6.617451759647824e-07, -7.496739270709606e-07, -8.986496232943575e-07, -1.171595280858216e-06, -1.736510986316704e-06, -3.163676234493161e-06, -8.249181140479859e-06, -4.090811157112002e-05, -4.478090737373076e-04, -9.891580144532953e-04, -6.959202881412358e-03, -1.546411311144996e-02, -6.439735946059477e-02, -2.185156820421171e-01, -2.556246098744267e-01, -9.300568930399075e-01, -7.241241877133120e-01, -8.282504228873327e-01, -9.126795309046887e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms0_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.348346937369592e-05, 8.119780000020863e-05, 9.378679674390771e-05, 1.155111327892141e-04, 1.561535399100449e-04, 2.415960971903694e-04, 4.540006763354984e-04, 1.123361465386370e-03, 4.028011250359081e-03, 1.854678993359683e-02, 5.826018020237683e-03, 8.174855496645555e-03, 2.843372318180917e-02, 9.458743749683499e-02, 9.975789418107422e-02, 8.013073180067911e-03, 3.279569086490689e-03, 1.408015304378774e-06, 8.796176328810610e-12, 2.217068925571100e-19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.085998625681767e-02, -1.122377159454486e-02, -1.175400375439582e-02, -1.252485703486593e-02, -1.362623724222116e-02, -1.509143324894721e-02, -1.645852966670391e-02, -1.422928952441259e-02, 1.232712749540212e-02, -3.027672350607177e-02, -2.414037554616434e-01, -1.038345401740312e+00, -1.746386347818564e+00, -1.812850855809222e+00, -4.008047095313577e+00, -2.245331806621228e+01, -3.560720562259397e+01, -3.748674947546551e+02, -9.715534282341421e+03, -7.985710232575693e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms0_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.302851883397796e-08, -3.961168684742719e-08, -5.139496593763812e-08, -7.459384889312802e-08, -1.269403212330009e-07, -2.704365689466826e-07, -7.890052410601858e-07, -3.549610156076382e-06, -2.814088008041981e-05, -1.892543550056873e-04, -5.527984872470721e-04, 3.148691304645157e-03, -1.304361157524672e-01, 2.505745274629280e-01, 1.538646365225911e+00, 3.791910122461416e+02, 3.823212643962003e+03, -8.297208072312367e+04, -1.159828089429981e+07, -9.455864518560871e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms0_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.283308433553311e-05, 5.934795144568917e-05, 7.011511914541195e-05, 8.901770305711936e-05, 1.251924258932596e-04, 2.034601326441924e-04, 4.048101660875430e-04, 1.063196352050810e-03, 3.988094113532277e-03, 1.067507529785454e-02, 7.084973525173654e-03, 4.927541897644638e-02, 5.845250959059040e-01, 8.696223007420588e-02, 3.120127585862060e-01, -3.737984392590406e+01, -4.550057683855297e+01, -1.603879453206767e+00, -2.307150893132254e-03, -9.172951720300971e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms0_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.076908607069094e-12, 1.370848273835672e-12, 1.938591949108971e-12, 3.187129612945226e-12, 6.497823258508501e-12, 1.799713027056832e-11, 7.695137499123679e-11, 6.064057039352751e-10, 1.113921140546878e-08, 3.033701470709065e-07, 7.343611374204319e-07, 3.637774882129139e-04, -2.795351317820691e-02, 1.057501395208794e-01, -2.403413612743305e+00, -7.870687866422223e+03, -1.222795710655252e+06, 2.242651579207684e+08, 4.210027131101458e+12, 2.665733544418193e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms0_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.533304588051403e-09, -1.835798419268677e-09, -2.377284512217078e-09, -3.444095394737422e-09, -5.856364159370794e-09, -1.250441574119880e-08, -3.683354581740741e-08, -1.702911827720476e-07, -1.456440085745937e-06, -1.213299405449512e-05, 3.451881142774476e-05, 6.359772453956207e-04, 1.018830235747094e-01, -7.786139550370359e-02, 3.326151854544119e+00, 7.643338155802365e+02, 1.192980231005742e+04, 1.172393235195631e+04, 1.853992300420826e+03, 5.430978190362261e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms0_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.195122330665971e-06, 2.471953833166856e-06, 2.931258897518943e-06, 3.742194737906147e-06, 5.307128350579706e-06, 8.735469724665890e-06, 1.772614187922113e-05, 4.807439120717223e-05, 1.913666110283481e-04, 4.825291605929284e-04, -6.681761493927502e-04, -5.366663669926709e-03, -3.511854263586819e-01, -1.461429938182328e-02, -2.691777059915163e+00, -7.206219259575464e+01, -1.014307706425179e+02, -3.150599273702310e+00, -4.338299747921232e-03, -1.697432880589575e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
