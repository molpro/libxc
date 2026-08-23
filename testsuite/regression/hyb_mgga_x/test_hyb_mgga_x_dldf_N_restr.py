
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_dldf_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_dldf", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.282835693547749e+00, -1.277598526640698e+00, -1.269502713709484e+00, -1.256699207488023e+00, -1.235926739556936e+00, -1.201416145882403e+00, -1.143497964199037e+00, -1.049352928842208e+00, -9.156845552450057e-01, -7.735452452998258e-01, -5.855947473733003e-01, -2.924684338327397e-01, -2.193386525046395e-01, -1.903865828812272e-01, -1.593107524896185e-01, -1.434140088858497e-01, -1.341464860158620e-01, -6.912534712392299e-02, -1.556201652144404e-02, -1.727942521410163e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_dldf_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_dldf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.456877157271455e-01, -7.542192779679524e-01, -7.665195735608239e-01, -7.839774204255342e-01, -8.076980148736740e-01, -8.361993606246643e-01, -8.578346959232891e-01, -8.320353856333489e-01, -6.739294603961972e-01, -3.645633052613892e-01, -1.842201773705076e-01, -2.704179034659547e-01, -2.379154703414496e-01, -1.754598705143760e-01, -9.705301002441317e-02, -1.617023516458213e-02, -4.438643508782059e-02, -7.724016397342630e-02, -2.057730882405072e-02, -2.303676700118690e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_dldf_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_dldf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.914272762835850e-06, -2.104997005053279e-06, -2.411139697287151e-06, -2.926045883566049e-06, -3.850853274875774e-06, -5.670600125732012e-06, -9.727630334350035e-06, -2.043380316939658e-05, -5.603458013812994e-05, -2.201886259452768e-04, -1.275506033831822e-03, -5.244955319426997e-03, -8.364473953427239e-03, -1.947793376396141e-02, -8.858146059954568e-02, -7.859411536237262e-01, -8.387764177648375e+00, -3.196291602474653e+01, -4.465239875634987e+01, -4.968494240115150e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_dldf_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_dldf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.919394173749643e-02, -1.870466603338043e-02, -1.797535463059074e-02, -1.687999688653041e-02, -1.523077568938291e-02, -1.278213730968585e-02, -9.354122069664050e-03, -5.339656513593352e-03, -2.633799739724505e-03, -3.133137273183768e-03, -3.699599198534094e-03, -4.719873860011881e-03, -1.275259900139694e-02, -1.517414921612429e-02, -1.324813811701381e-02, -1.929697592887963e-02, -8.280114787807479e-03, -6.474163330911288e-04, -7.733755112981517e-06, -1.198444939756199e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_dldf_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_dldf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.525456677632444e-03, 3.775787547282629e-03, 4.139324652556038e-03, 4.656354134027404e-03, 5.337906686413004e-03, 5.987874671309297e-03, 5.398726903946541e-03, -1.935332732282194e-03, -3.555902699218180e-02, -1.332241486161315e-01, -3.027944449092319e-01, -2.772165059744908e-01, -1.304858858309114e-02, -2.419438223080754e-01, -2.303455851308138e+00, -6.615736280499135e+00, 1.731336119652432e+02, 7.998964897479564e+02, -2.164904214114222e+04, -1.986422132203217e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_dldf_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_dldf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.015408050852294e-08, 2.335476092234920e-08, 2.882610650595815e-08, 3.889408560071955e-08, 5.944791794514003e-08, 1.079683821099328e-07, 2.481599549954618e-07, 7.870622565004410e-07, 3.970161890320110e-06, 3.896584161905523e-05, 7.644319985014129e-04, 1.199615717839150e-02, 2.919643769036123e-02, 1.222362729763437e-01, 1.493325478743931e+00, 3.840037743829492e+01, -1.148413791504858e+04, -3.461985899833541e+06, -6.212944295759274e+08, -5.147204894775332e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_dldf_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_dldf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.657780444466093e-04, -1.787554756276313e-04, -1.984635759346177e-04, -2.288201341838637e-04, -2.759461277862385e-04, -3.475567626505246e-04, -4.426887654194348e-04, -4.967392230017556e-04, -2.383198298748920e-04, 4.131288707575028e-04, -7.053377863448180e-04, -1.552796354758769e-03, -1.029142974439030e-01, -2.109339538830790e-01, 1.462824657386774e-01, -6.951183064317553e-01, -1.448292595303071e+01, -5.536704773377280e+01, -8.089271029179707e+01, -9.311911771798572e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_dldf_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_dldf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.976852246990212e-15, 9.028414567801530e-15, 1.306624960912559e-14, 2.218305748124789e-14, 4.725223036359383e-14, 1.386737014693112e-13, 6.373637915530639e-13, 5.449406748441193e-12, 1.088618127626445e-10, 6.686625055925988e-09, 1.208372067834444e-06, 6.934689814524917e-05, 3.333515255293459e-04, 4.379949962883277e-03, 4.209392132482392e-01, 3.476748205104589e+02, 1.596859345959835e+06, 1.080897853685590e+10, 2.259340751080024e+14, 1.451097422929550e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_dldf_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_dldf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.599313778693042e-10, -1.829495976214993e-10, -2.213041068067632e-10, -2.890642779126193e-10, -4.183578543858252e-10, -6.895286814641942e-10, -1.318431162121274e-09, -2.925946947098310e-09, -9.615590752746964e-09, -1.512950901218122e-07, -5.015788901478369e-06, -1.366687092919246e-04, -1.182758795284429e-03, -7.268204246226317e-03, -1.099481726477405e-01, -9.084213482642527e+00, -5.271933769139557e+02, -9.301169246700161e+03, -7.769385251998318e+04, -8.925582596152310e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_dldf_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_dldf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.282286860021280e-06, 5.666478846807799e-06, 6.248610497904283e-06, 7.142664379400248e-06, 8.525769620544937e-06, 1.062039445535756e-05, 1.340696331186970e-05, 1.515358400319727e-05, 9.393244888281980e-06, 3.666477980082058e-06, 1.055090275600337e-04, 5.049714700454732e-04, 4.637109158066416e-02, 1.485613262617461e-01, 2.253273068756973e-02, 2.009320319909410e+00, 1.932354387158928e+01, 5.771909230548511e+01, 8.672025336537553e+01, 1.062358569125119e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
