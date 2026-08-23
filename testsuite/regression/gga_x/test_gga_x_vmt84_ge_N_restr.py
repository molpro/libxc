
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_vmt84_ge_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt84_ge", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.243869260326142e+00, -4.161219225853667e+00, -4.045474030297442e+00, -3.885281499072684e+00, -3.667306543796772e+00, -3.377868185480473e+00, -3.006812623963410e+00, -2.554574544904504e+00, -2.041900231830209e+00, -1.514411903500194e+00, -1.012747698514743e+00, -6.499478652685560e-01, -5.569488075533638e-01, -4.595428176169133e-01, -3.311760706848311e-01, -2.132462264181999e-01, -1.205961130174664e-01, -3.773410676293029e-02, -4.538565383991084e-03, -2.953295763628845e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_vmt84_ge_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt84_ge", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.447029812158372e+00, -5.333223665585710e+00, -5.173647179899512e+00, -4.952373783803821e+00, -4.650409642825567e+00, -4.247618405089768e+00, -3.727514565445992e+00, -3.086563652568481e+00, -2.350362621814034e+00, -1.603630334197885e+00, -1.023827321738410e+00, -8.139542117593001e-01, -7.222154862137373e-01, -5.665349484159911e-01, -3.670204120046935e-01, -1.956825541805022e-01, -1.181047269386695e-01, -8.111018818575948e-02, -6.830427208451719e-03, -4.490499245284170e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_vmt84_ge_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt84_ge", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.268952392587474e-06, -2.458138404907472e-06, -2.757605917669088e-06, -3.251792813370065e-06, -4.117310470338036e-06, -5.767231753081188e-06, -9.312948249702941e-06, -1.831852797353436e-05, -4.695833215511584e-05, -1.672343569026377e-04, -8.696239273190685e-04, -4.224235666546421e-03, -7.572491589930603e-03, -1.716029245217583e-02, -7.024336983807015e-02, -4.746783625986528e-01, -2.893929824582264e+00, 6.939974335165699e+01, 2.120979875505939e+02, 8.661911007566880e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_vmt84_ge_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt84_ge", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.159039110788934e-02, -1.211810760750435e-02, -1.292050968602293e-02, -1.417073643266494e-02, -1.618847569249757e-02, -1.961381355253466e-02, -2.586245500917622e-02, -3.843967493606869e-02, -6.681586045866464e-02, -1.337262709634280e-01, -2.975759428027572e-01, -5.366973853090421e-01, -6.478488526547195e-01, -1.125208858290710e+00, -2.690598690906215e+00, -4.554426173902333e+00, 6.445432041883177e+01, 1.485475254659160e+03, -4.253892308605858e+03, -1.370041698021114e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_vmt84_ge_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt84_ge", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.557813358149806e-08, 1.788375219372762e-08, 2.179888517325909e-08, 2.894443317352870e-08, 4.340024344669532e-08, 7.724615604434650e-08, 1.745058574473284e-07, 5.439113758554367e-07, 2.532945777445066e-06, 1.732145194541156e-05, 2.267964131172878e-04, 7.913272773107508e-03, 2.316699354496365e-02, 8.956260037499554e-02, 8.146632771041816e-01, -5.615561549783311e+00, -7.086836435847516e+03, -5.240268504309542e+06, -1.012202104294082e+09, 2.814773357958771e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_vmt84_ge_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt84_ge", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.410578503998629e-14, 1.797824744301237e-14, 2.547057728593409e-14, 4.198850449129928e-14, 8.595228099138102e-14, 2.395032899710865e-13, 1.032918052985466e-12, 8.221033137102839e-12, 1.517155832367512e-10, 8.251518240700105e-09, 1.318206840446659e-06, 9.475843808208596e-05, 5.159044744089563e-04, 6.523843656885036e-03, 5.495714711525183e-01, 3.211949696274355e+02, 7.467624277732708e+05, 5.329798646294124e+09, 6.009272527288547e+12, -6.583902106244760e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
