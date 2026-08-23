
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_hse06_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse06", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.298979698355193e+00, -3.236966680741465e+00, -3.150166010608900e+00, -3.030125746666501e+00, -2.866980644010800e+00, -2.650741387723729e+00, -2.374218733489566e+00, -2.037747279342796e+00, -1.652710309970234e+00, -1.239691519364150e+00, -8.373333100460564e-01, -5.562532515383612e-01, -4.885592568577038e-01, -4.061971302688209e-01, -2.977601801995746e-01, -1.916814293215279e-01, -1.047001932973858e-01, -4.105519258145523e-02, -8.769105534074690e-03, -9.701624276128925e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_hse06_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.161574792341517e+00, -4.073400730733850e+00, -3.949666107601632e+00, -3.777922297339059e+00, -3.543323870827629e+00, -3.230402023242604e+00, -2.828238699421933e+00, -2.343627652086482e+00, -1.825593457148519e+00, -1.318629420412857e+00, -8.632613927864198e-01, -6.955631288924634e-01, -6.328602024683534e-01, -5.034646815697118e-01, -3.522724463753667e-01, -1.971530463704373e-01, -1.187735451609006e-01, -5.341159752550094e-02, -1.168823028841645e-02, -1.293545713552818e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hse06_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.270724679471800e-06, -2.485120867558758e-06, -2.827184713222905e-06, -3.397371667978565e-06, -4.407475433367007e-06, -6.350417305217584e-06, -1.049935577568689e-05, -2.040930962017579e-05, -4.593225495265927e-05, -1.303422408415018e-04, -6.502759440595719e-04, -2.345952742766127e-03, -3.336824715826116e-04, -8.675991503032648e-03, -3.217498235237683e-02, -2.786344177832800e-01, -1.138309012911599e+00, -8.555126981906455e-01, 6.036659648291788e-03, 1.504922553420553e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hse06_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.011278686299366e-02, -1.061530540151377e-02, -1.137940316612819e-02, -1.256678267535725e-02, -1.446274241660715e-02, -1.757288074614810e-02, -2.266727868126411e-02, -2.976328550807044e-02, -3.351146648161334e-02, -8.745210909384211e-02, -3.008888080353935e-01, -4.825555768044809e-01, -5.247112952252092e-01, -9.836686380642761e-01, -1.739893799982832e+00, -3.710045546284581e+00, 5.111083355053339e-01, -3.218279667420119e+02, -1.361196238747991e+04, -1.116799133711411e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hse06_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.806452818127514e-08, 3.220634065676816e-08, 3.917768497536169e-08, 5.168940245818557e-08, 7.615010116133349e-08, 1.292181839070298e-07, 2.548639989784522e-07, 5.054525606916013e-07, -1.114873361397816e-07, 6.867723700244522e-06, 3.586763553679360e-04, 1.203040554366801e-02, 2.426889497035852e-02, 1.129978861791960e-01, 2.736240185177130e-01, -4.944483244995222e+00, -2.435325368754675e+03, -4.008775541283973e+05, 1.380746113142922e+05, 2.578585853613300e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_gga_xc_hse06_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.315513381317367e-13, -1.576131731171749e-13, -2.034173511398723e-13, -2.901248111043479e-13, -4.682989156076054e-13, -8.416219377675367e-13, -1.109523690679393e-12, 1.314488297173732e-11, 4.580508700877819e-10, 8.708666127140636e-09, 4.306175919056617e-07, -6.390372274930128e-04, -9.412485218647335e-03, -2.609461849912620e-02, 2.259200455472721e-01, 1.850498077076767e+02, 2.694951773779432e+05, 9.865160550979017e+08, -4.600982050329903e+10, -6.593259128892691e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
