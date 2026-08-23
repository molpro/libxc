
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_bb1k_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_bb1k", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.564143740583095e+00, -2.516336235401032e+00, -2.449379932128215e+00, -2.356698825564472e+00, -2.230554887498807e+00, -2.062968417239754e+00, -1.847877329846020e+00, -1.584968247138535e+00, -1.284575720359156e+00, -9.691469649310011e-01, -6.589171612837734e-01, -4.540688550719841e-01, -3.738312468067113e-01, -3.060225278707227e-01, -2.239259119994049e-01, -1.447625464371864e-01, -8.689529847573989e-02, -5.275344889428341e-02, -3.391099457244527e-02, -2.353346675078475e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_bb1k_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_bb1k", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.197920993085748e+00, -3.131919222751446e+00, -3.039413033223247e+00, -2.911226906448092e+00, -2.736481047463086e+00, -2.503792596900052e+00, -2.204225889436922e+00, -1.836946610348319e+00, -1.418348336074384e+00, -9.948044505002615e-01, -6.621282422835959e-01, -5.663331307739298e-01, -4.657706636812940e-01, -3.738110545822343e-01, -2.536342007316240e-01, -1.403735429751985e-01, -6.049782761996819e-02, -2.379082333165636e-02, -9.264463361184002e-03, -3.848974786293906e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_bb1k_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_bb1k", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.067807537311923e-06, -2.227804925425506e-06, -2.479209788631254e-06, -2.889684814426003e-06, -3.597576963779955e-06, -4.917149646869604e-06, -7.662488559514480e-06, -1.431881241058180e-05, -3.419661995599679e-05, -1.122919280089042e-04, -5.271409659019914e-04, 3.446745813112017e-03, 2.809763861314388e-03, -4.912317030234873e-03, -3.088149577587788e-02, -2.579089581073651e-01, -3.705578636078040e+00, -1.048131430624298e+02, -9.787955956594456e+03, -5.820588179071507e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_bb1k_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_bb1k", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.375567663333887e-04, -3.424569951505815e-04, -3.492532570038715e-04, -3.584443056041141e-04, -3.702743158825234e-04, -3.839209698517952e-04, -3.954169130397691e-04, -3.935947374396980e-04, -3.585826108127490e-04, -2.919286190495680e-04, -3.934739840274066e-04, -5.911249725741185e-03, -1.215099559354933e-02, -8.595759447999490e-03, -5.100653368791454e-03, -1.941883042677229e-03, -3.394174606475803e-04, -2.122505356273373e-05, -3.221485433594406e-07, -6.299510954859021e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_bb1k_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_bb1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.893839538190315e-03, -7.203689993454165e-03, -7.673734479194096e-03, -8.403485733757446e-03, -9.574491644300924e-03, -1.154371072760636e-02, -1.507931883951706e-02, -2.201431797860631e-02, -3.723051835698138e-02, -7.553651800958743e-02, -1.949162265848008e-01, -1.707828674554994e-01, -2.882919578906971e-01, -6.400140011630447e-01, -1.743890134481419e+00, -6.328906368221430e+00, -2.173653050410007e+01, 5.575838694620830e+01, 1.066332108845677e+04, 6.032001122490486e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_bb1k_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_bb1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.201708005763445e-08, 1.371585943606518e-08, 1.658011380281755e-08, 2.175400890755186e-08, 3.206390908730638e-08, 5.566598239454659e-08, 1.212174965369738e-07, 3.578109779827179e-07, 1.561123883298757e-06, 1.144433256927049e-05, 2.546224372984339e-04, 5.393397239430174e-03, -6.895724857778444e-03, 8.641777435497285e-02, 9.349819169682434e-01, 1.997493488709790e+01, 2.914085273974631e+02, -6.698884015002783e+05, -5.845321111789547e+09, -1.977998969267732e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_bb1k_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_bb1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.617578248211794e-06, -1.829183131956684e-06, -2.174872864687964e-06, -2.769351600943677e-06, -3.864806628696993e-06, -6.072754570443859e-06, -1.103528589734494e-05, -2.357149524392739e-05, -5.858087267398961e-05, -1.689407216062556e-04, -9.018020406182861e-04, -1.440910780837978e-02, -1.730638894015353e-02, -7.371400611027794e-02, -2.381614667286154e-01, -6.950994680341143e-01, -1.626510888596801e+00, -3.216408521515742e+00, -5.568582976990760e+00, -8.117935153904899e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_bb1k_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_bb1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.847479125959825e-14, 2.259422800462133e-14, 3.020181002118416e-14, 4.593590330784535e-14, 8.442847270182630e-14, 2.057470975784106e-13, 7.692999243220507e-13, 5.462564819557242e-12, 9.220852553553860e-11, 4.113815961700658e-09, 2.047333620063704e-07, -2.685861022029595e-03, -1.444987332938452e-02, -4.722537179625790e-02, -7.702007893325540e-01, 1.074299643731661e+01, 3.073999366451558e+05, 1.126911160598687e+10, 1.403164445551685e+16, 4.668378355432293e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_bb1k_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_bb1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.916050179873967e-11, 3.446096601149646e-11, 4.373770127880464e-11, 6.138564941131548e-11, 9.912267028079563e-11, 1.939545178257547e-10, 4.901359636795507e-10, 1.715978639403007e-09, 8.928588069670853e-09, 7.918849669045711e-08, 2.762267028323555e-06, 1.573286494359455e-03, 1.236868686480504e-02, 3.538576891525784e-02, 2.619793796742148e-01, 4.173191644341568e+00, 1.214262748700988e+02, 7.899879129525616e+03, 1.637581142200523e+06, 1.839943426341288e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_bb1k_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_bb1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.479281294991928e-138, -3.256046006393622e-138, 0.000000000000000e+00, -5.162548007931523e-138, -4.241166238933286e-138, 0.000000000000000e+00, -8.542738895584960e-138, 0.000000000000000e+00, -3.369153414520278e-137, -1.279777249822558e-136, 0.000000000000000e+00, 0.000000000000000e+00, -1.436969208310206e-133, 5.489076604171861e-133, 0.000000000000000e+00, -5.005130872864918e-132, -1.749655682672519e-131, 0.000000000000000e+00, -4.991570423523757e-131, 1.604205400755743e-130]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
