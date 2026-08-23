
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_vsxc_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_vsxc", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.371910576443784e-02, -4.435425033200295e-02, -4.526444127183134e-02, -4.656016421326772e-02, -4.837440609386828e-02, -5.080702024441752e-02, -5.367833241783028e-02, -5.563364743539277e-02, -5.190158282422616e-02, -3.771211564201671e-02, -5.882592360193898e-02, -1.643044383241773e-01, -3.060380033121176e-02, -3.321150974701665e-02, -2.761343175181660e-02, -4.298525977988643e-03, 4.196134140706374e-03, 4.663888378484907e-04, 7.087495616163054e-06, 1.262025607101013e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_vsxc_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_vsxc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.797350978884309e-02, -6.665715802659568e-02, -6.490286475043114e-02, -6.269791984866604e-02, -6.027941802156998e-02, -5.864571216892149e-02, -6.092199047939089e-02, -7.533960958877754e-02, -1.154875060079906e-01, -1.603934515413269e-01, -1.486113468091470e-01, 1.913197907516520e-01, -3.025639877749284e-02, -2.697267530539819e-02, -6.259658271168944e-02, -9.992664031127746e-02, -2.997546393229734e-02, -1.766731267781503e-03, -2.606508923443984e-05, -5.311725626671312e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_vsxc_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_vsxc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.604811850701725e-06, 1.652552248467556e-06, 1.721684748599048e-06, 1.822122500873340e-06, 1.969758842111266e-06, 2.198563292991488e-06, 2.640198396817767e-06, 4.139949403412300e-06, 1.324373665252533e-05, 7.732127414699865e-05, 8.130731735959292e-04, 1.951380966246307e-02, -1.207837427818839e-03, -7.278849374502378e-03, 4.713403092392879e-02, 1.042262766384089e+00, 6.843994567870431e+00, 1.854492150023797e+01, 3.421047422970965e+01, 5.125066882266466e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_vsxc_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_vsxc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.144481707585583e-03, -3.077104726361276e-03, -2.979628085107826e-03, -2.838435636441950e-03, -2.634123936030444e-03, -2.341297585590724e-03, -1.937716213333287e-03, -1.456839617976208e-03, -1.184237127918293e-03, -1.919567645065105e-03, -6.984385576231746e-03, -5.388522084116306e-02, -3.347762535487361e-04, 5.313428399558309e-03, -1.174197239314719e-02, -6.804654965104964e-02, -5.078996494369190e-02, -5.119406477173703e-03, -8.682177347028786e-05, -1.771406328147503e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_vsxc_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_vsxc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.831218953594939e-04, -4.771126571530359e-04, -4.573416207387337e-04, -3.995492104994879e-04, -2.323830312849550e-04, 2.741034967556849e-04, 1.946590498590368e-03, 8.053422076340244e-03, 3.092321519197070e-02, 9.098265499131879e-02, 2.063182070804324e-01, 9.999361347752790e-02, -3.047146642703487e-01, -9.586394805910413e-03, 3.540507727015538e+00, 2.634819930358076e+00, -1.490754710287233e+02, -4.631119583015508e+02, -7.993312740759138e+02, -1.143858135027624e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_vsxc_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_vsxc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.946531842630402e-09, 6.165820856314222e-09, 6.286828963861998e-09, 5.801192163998080e-09, 2.561861202895721e-09, -1.362165978877809e-08, -1.015458392895882e-07, -7.012808285857804e-07, -6.159985531273572e-06, -6.347816538809431e-05, -2.186915434706041e-04, -9.217149931705743e-02, -1.145702469208079e-02, -5.519327061850347e-02, -5.338319149406102e+00, -5.414986529104316e+01, 1.870421362214133e+04, 2.178082762273828e+06, 4.546564646333935e+08, 4.930870420600018e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_vsxc_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_vsxc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.478494142535283e-06, -2.302597036553655e-06, -1.933704415357217e-06, -1.097170162221203e-06, 9.896421394283777e-07, 6.859186859755723e-06, 2.606994586500644e-05, 1.012571426772910e-04, 4.419318124751474e-04, 1.676950932896675e-03, -4.217438418675745e-03, 9.484205653706312e-02, 1.301936012675974e-01, 8.376410061734930e-02, 1.240116510600571e+00, 4.156747307732033e+00, -1.021153981051093e+02, -4.481227446908511e+02, -8.572483964175102e+02, -1.261089367561074e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_vsxc_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_vsxc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.545269079371350e-13, 1.991090007708755e-13, 2.861668602078272e-13, 4.802824714718484e-13, 1.003157560559817e-12, 2.843462322976939e-12, 1.224937823270063e-11, 9.178915603856377e-11, 1.344416887685336e-09, 3.407429628425509e-08, -6.326358959230772e-06, -4.682957234966541e-03, -1.034668640909223e-02, 6.618510595766937e-02, 5.948634656238545e+00, 2.069969932231675e+01, -1.914198592991119e+06, -6.846713087702679e+09, -1.624591820366363e+14, -1.303945246188916e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_vsxc_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_vsxc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.428148970582056e-10, -9.561005335155963e-10, -1.146885471290030e-09, -1.491625425008958e-09, -2.181989829022888e-09, -3.790026026319935e-09, -8.475179477779254e-09, -2.744878758931246e-08, -1.468205752304166e-07, -1.092007486884006e-06, 5.681550005400332e-05, 8.869706199594240e-03, 1.746896326660804e-02, -4.122452709879185e-02, -1.270563866402925e+00, -5.763922290961617e+01, -5.919599602880033e+02, 2.423744984858216e+04, -2.484942614319915e+07, -5.856004540025683e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_vsxc_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_vsxc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.227884512899330e-06, 2.361884823488577e-06, 2.568672659204511e-06, 2.897513974181527e-06, 3.443115335759973e-06, 4.403892205924331e-06, 6.241382625727620e-06, 1.016473665271683e-05, 1.950204511862793e-05, 3.192511502269925e-05, -4.624473793956779e-04, -1.375455868862885e-02, -7.035993477487033e-02, 8.116646955703190e-03, 1.238855855375709e-01, 6.524354704701437e+00, 1.044501894029474e+02, 4.422351737003006e+02, 1.027586189326259e+03, 1.747971901869004e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
