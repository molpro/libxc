
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_vv10_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_vv10", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.384386446590067e+00, -4.303729402157508e+00, -4.190941154863074e+00, -4.035165333555647e+00, -3.823801474735682e+00, -3.544126071493954e+00, -3.186670567617703e+00, -2.750054941668437e+00, -2.244805800961185e+00, -1.694205567229059e+00, -1.138558398936142e+00, -7.170104244657505e-01, -6.154245380206433e-01, -5.185219884832205e-01, -3.833098104348984e-01, -2.412561120190807e-01, -1.288141293218530e-01, -5.761095331210936e-02, -2.128682982104154e-02, -5.611090432093796e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_vv10_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_vv10", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.367820057605138e+00, -5.248741005980468e+00, -5.082079849123678e+00, -4.851794568870044e+00, -4.539710686573370e+00, -4.129256398324582e+00, -3.614146884795750e+00, -3.012083104790799e+00, -2.370233305012045e+00, -1.739374461232455e+00, -1.165939173165096e+00, -8.553507872541311e-01, -7.861121456700397e-01, -6.109709910720659e-01, -4.289944423552784e-01, -2.557088114695057e-01, -1.251271266818553e-01, -5.065798669193747e-02, -1.716313479986583e-02, -4.489340742576592e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_vv10_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_vv10", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.911621118722130e-06, -5.367350369088060e-06, -6.087097993430906e-06, -7.267321885922078e-06, -9.302471068000730e-06, -1.304694054526151e-05, -2.050543204200512e-05, -3.683122445816118e-05, -7.747389563123878e-05, -2.069747325124553e-04, -9.275584795415047e-04, -7.125812708953325e-03, -8.046758555966869e-03, -2.620925053578556e-02, -7.202550437781546e-02, -3.445110024191688e-01, -3.153384603358493e+00, -5.893878486181757e+01, -3.054648824954771e+03, -6.326372561802620e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_vv10_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_vv10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.483438849644539e-02, -1.549344266578368e-02, -1.646432609928720e-02, -1.789846399338486e-02, -2.000552963834271e-02, -2.301481727423752e-02, -2.696509011176539e-02, -3.125059655507501e-02, -3.538773637824529e-02, -4.663656321959016e-02, -1.106092324882950e-01, -6.145236712497922e-01, -7.887486198825722e-01, -1.132709598224722e+00, -1.710156408726588e+00, -6.420628121351077e+00, -1.228164546125487e+01, -2.397346721744470e+01, 1.043667472332810e+04, 2.321398469598819e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_vv10_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_vv10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.432788901147940e-08, 6.102976217349255e-08, 7.177973534547500e-08, 8.964294032542855e-08, 1.203532974784528e-07, 1.733103192802065e-07, 2.506346237836183e-07, 2.229566077290467e-07, -1.280127746932801e-06, -1.948276995537274e-05, -3.239117245345235e-04, 1.510314800303988e-02, 7.193566452634371e-02, 9.808248780378094e-02, -1.806206801129878e-01, -1.532247665755744e+00, -2.002556210561606e+03, -1.127807204459715e+06, -8.295220682636466e+09, -1.310347559093643e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_vv10_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_vv10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.023992615889239e-13, -2.263235298954131e-13, -2.588506044507925e-13, -2.902071481852060e-13, -2.389661311720181e-13, 4.628136862860656e-13, 6.341114641665648e-12, 6.466106501885859e-11, 9.220607220003647e-10, 2.628705812726450e-08, 2.861475431109376e-06, -6.349483477773618e-05, -1.791880363598909e-02, 1.979206105576935e-02, 1.396463074231794e+00, 2.061935566073412e+02, 4.235639653857125e+05, 8.042609241556944e+09, 6.141026984638747e+15, 7.390014085000908e+23]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
