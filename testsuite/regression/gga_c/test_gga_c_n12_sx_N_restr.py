
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_n12_sx_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_n12_sx", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.542149990302941e-01, -1.516431309278415e-01, -1.478803560886603e-01, -1.423473040169328e-01, -1.341738237556641e-01, -1.220873960430588e-01, -1.043704120964944e-01, -7.907392092512247e-02, -4.427443612207203e-02, 1.205911189632386e-03, 2.195019065408395e-02, -7.124172804608571e-02, -9.013172898980076e-02, -5.443498535329646e-02, -1.265921999977776e-02, 3.712584493323116e-02, 2.900231402546589e-02, -1.800596969066106e-03, -1.063370503029789e-03, -8.218868604512719e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_n12_sx_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_n12_sx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.887876861066928e-01, -2.896203388185650e-01, -2.905556900792832e-01, -2.913104174061417e-01, -2.910742210999997e-01, -2.878997780611938e-01, -2.780083490014659e-01, -2.572332595528531e-01, -2.309620899924985e-01, -2.166219466336037e-01, -1.897324558342313e-01, -1.757796752731995e-01, -1.475568736955946e-01, -1.525622304650860e-01, -1.233022343239531e-01, -6.482135593904853e-02, 8.284001128227839e-02, 6.758071425203418e-03, -1.333416077568389e-03, -1.150936031954833e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_n12_sx_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_n12_sx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.308271561694262e-06, 1.434378839697595e-06, 1.632642205939369e-06, 1.955256158009652e-06, 2.504616066657154e-06, 3.497135765341727e-06, 5.440960936922995e-06, 9.804748122727223e-06, 2.303220865973210e-05, 8.774159517623410e-05, 5.705599944682446e-04, 7.702167272751191e-03, 1.717278627019635e-02, 3.384066953052699e-02, 1.026101468709809e-01, 5.780911675479616e-01, -3.267032862726377e+00, -2.086198896715157e+01, -3.558022577294300e+01, -4.438420868324525e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_n12_sx_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_n12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.570990927608311e-04, 7.513775563818554e-04, 7.275179989977157e-04, 6.565904638892253e-04, 4.677784117828610e-04, -4.354980892549022e-06, -1.078691632626350e-03, -2.864047007952515e-03, -2.030166231425487e-03, 5.096072458895476e-03, -3.872311886677002e-02, -3.625153762673906e-02, 1.929727230002533e-01, -2.494787661965722e-01, 1.131962474869630e-01, -2.555666383520360e+01, -1.597726739007245e+01, 1.055537576769888e+03, 5.344665374787161e+01, -1.180925970826970e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_n12_sx_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_n12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.503320573326890e-09, -1.016227070689066e-08, -1.100722076844549e-08, -1.185236638425939e-08, -1.169052367626171e-08, -6.132844901961047e-09, 2.251235504730345e-08, 1.269610670843455e-07, 9.182762481936798e-08, -3.555758010651156e-06, 6.798120300862270e-05, 2.241680314900803e-04, -8.762369354062717e-02, 5.887849151369662e-02, -3.492727131989852e-01, 1.317987401261396e+02, 2.193119263073392e+03, -2.274767523629627e+06, -4.919329635293785e+08, -4.588589925355760e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_n12_sx_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_n12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.213698268198649e-14, -3.791134741283641e-14, -7.185416941434690e-14, -1.553915651434442e-13, -3.993763439710697e-13, -1.282981201950460e-12, -5.447785657931241e-12, -3.218167024421787e-11, -2.838536945209068e-10, -7.940060187273722e-09, -1.652216916921586e-06, -1.558990441602593e-03, 8.654151899708747e-03, -1.122217687700576e-01, -1.871740198410514e+00, -1.105833215329255e+03, 1.816437339992792e+05, 7.187481773963252e+09, 1.802522843727910e+14, 1.296304940316480e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
