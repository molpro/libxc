
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pbe_jsjr_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_jsjr", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.261115223307172e+00, -4.178733837139536e+00, -4.063376991496136e+00, -3.903746763130162e+00, -3.686586991827282e+00, -3.398328455309727e+00, -3.028957401412644e+00, -2.578985772896438e+00, -2.068643476981649e+00, -1.540505855414156e+00, -1.031243877326404e+00, -6.541336566075444e-01, -5.586281072377396e-01, -4.631533378331055e-01, -3.362434794766233e-01, -2.165625545800995e-01, -1.169147550024901e-01, -4.165821706557327e-02, -8.767227359006849e-03, -9.701585546433868e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pbe_jsjr_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_jsjr", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.427509810725018e+00, -5.313538389459302e+00, -5.153738719638521e+00, -4.932177296162639e+00, -4.629876843094809e+00, -4.226796777091993e+00, -3.706800317235223e+00, -3.067509559977851e+00, -2.338066544314386e+00, -1.609595794483111e+00, -1.037652463048037e+00, -8.097925510634266e-01, -7.202214569184213e-01, -5.632758487168201e-01, -3.661379603686938e-01, -2.055317125135726e-01, -1.253832941646728e-01, -5.369011500905774e-02, -1.167063099325145e-02, -1.293517674027667e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_jsjr_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_jsjr", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.725126087559782e-06, -2.950044556250772e-06, -3.305565369960505e-06, -3.890977408401947e-06, -4.912792763289074e-06, -6.850014678142636e-06, -1.097466664856465e-05, -2.127681972319550e-05, -5.300885037999115e-05, -1.788343205153532e-04, -8.984862068183598e-04, -5.006021906491335e-03, -9.145135466195376e-03, -2.015966002988606e-02, -7.744129811259882e-02, -4.456159038259511e-01, -2.067779037917892e+00, -4.178162114254580e+00, -5.174570679848456e+00, -5.722591596186264e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_jsjr_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_jsjr", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.177138422227015e-02, -1.230867349239390e-02, -1.312509844542924e-02, -1.439568301725434e-02, -1.644168609787746e-02, -1.989906384885700e-02, -2.614180166409931e-02, -3.839505103829048e-02, -6.421240585946912e-02, -1.141901150624344e-01, -2.275746056910121e-01, -5.440497620335437e-01, -6.568762550043777e-01, -1.135059242322993e+00, -2.473132494685065e+00, -1.484895083393368e+00, 3.812690738060824e+01, -3.373772086596973e+02, -1.335489662646638e+04, -1.116516240896388e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_jsjr_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_jsjr", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.790999571760648e-08, 2.050705435215490e-08, 2.489803452910586e-08, 3.285882997566401e-08, 4.879430924912171e-08, 8.545278659455867e-08, 1.875291466731864e-07, 5.515993707743988e-07, 2.235310389939287e-06, 9.324229099107617e-06, 3.271144891174930e-05, 8.682984281521314e-03, 2.712133806120714e-02, 9.511190972675494e-02, 6.138902844999563e-01, -2.356236755638907e+01, -5.469596343074508e+03, -4.927649158231314e+05, -7.229246943282996e+07, -5.928736372365382e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_jsjr_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_jsjr", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.552696968344646e-14, 3.249657725186999e-14, 4.595799512648232e-14, 7.555766461176278e-14, 1.540146054413540e-13, 4.261963895801935e-13, 1.816345451797638e-12, 1.414350301235977e-11, 2.499968121161325e-10, 1.252548993246245e-08, 1.898941106698360e-06, 1.680493551890971e-04, 9.414107917538937e-04, 1.141834542623196e-02, 8.737268752215317e-01, 3.994718542722828e+02, 5.610937922334743e+05, 1.500422267108687e+09, 2.625983777054024e+13, 1.671402406477999e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
