
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_ob_pz_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ob_pz", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.173538700328557e-01, -1.167530812151915e-01, -1.158907915235022e-01, -1.146544742753150e-01, -1.128846502922252e-01, -1.103569610823038e-01, -1.067593515973537e-01, -1.016664009041596e-01, -9.452732934386057e-02, -8.478846008666702e-02, -7.301951248474595e-02, -6.464667059513159e-02, -6.111258308124273e-02, -5.583740961933536e-02, -4.906794367067429e-02, -3.869378291093496e-02, -2.520979738903033e-02, -1.175724630677729e-02, -3.218049236477860e-03, -4.141481919343328e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_ob_pz_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ob_pz", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.271714239218397e-01, -1.265625776432293e-01, -1.256885362852364e-01, -1.244349795064102e-01, -1.226396594146489e-01, -1.200738401221930e-01, -1.164183466288657e-01, -1.112358468606846e-01, -1.039555012075214e-01, -9.399386906901386e-02, -8.191727641995250e-02, -7.331912894767918e-02, -6.969670679857254e-02, -6.155732847296604e-02, -5.499451228568545e-02, -4.453869877065719e-02, -3.013363385145240e-02, -1.467946157423657e-02, -4.166450580688162e-03, -5.471133187603174e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_ob_pz_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ob_pz", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.555049762312851e-05, -5.901942156375776e-05, -6.438480757406285e-05, -7.295049184766100e-05, -8.726083107792596e-05, -1.127760591743590e-04, -1.627067961698530e-04, -2.742629289423501e-04, -5.743556081300112e-04, -1.600008994523318e-03, -5.689005068781144e-03, -1.436606553039420e-02, -2.137515788828138e-02, -2.558391540259612e-02, -8.704336360502860e-02, -5.185221168650934e-01, -5.545099905663939e+00, -1.085247118768585e+02, -4.224022610203444e+03, -4.526984390575393e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
