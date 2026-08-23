
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_rpw86_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rpw86", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.320216865334848e+00, -4.240603024774490e+00, -4.129310432449065e+00, -3.975675816829182e+00, -3.767370285192656e+00, -3.492045230431043e+00, -3.140723978727502e+00, -2.712565519703340e+00, -2.218218171984056e+00, -1.678900500536957e+00, -1.127276930988161e+00, -6.739639390877361e-01, -5.629172545605154e-01, -4.818426510288845e-01, -3.639931423925635e-01, -2.360525613792251e-01, -1.284486865760212e-01, -5.760683882671461e-02, -2.128682566144425e-02, -5.611090431960338e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_rpw86_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rpw86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.235611468731439e+00, -5.117501846844527e+00, -4.952248353327973e+00, -4.724017120956965e+00, -4.414954256188156e+00, -4.009001591574038e+00, -3.500747488307241e+00, -2.909479621395419e+00, -2.285133498436045e+00, -1.679697322115455e+00, -1.118570393058677e+00, -7.666595486983624e-01, -7.034519760263660e-01, -5.318511872213497e-01, -3.687167355628209e-01, -2.315314436266302e-01, -1.229598474774365e-01, -5.063169736323317e-02, -1.716310761973853e-02, -4.489340741693739e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_rpw86_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rpw86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.629690806211939e-06, -6.133504202434434e-06, -6.927851884486965e-06, -8.227607030819875e-06, -1.046316035705606e-05, -1.456538827844642e-05, -2.271884037315223e-05, -4.054703221877663e-05, -8.485089209411263e-05, -2.248795595811144e-04, -1.024004279990917e-03, -1.058880923276673e-02, -1.749981494790786e-02, -4.109276457162209e-02, -1.098746505797784e-01, -4.455459951503059e-01, -3.274565021328626e+00, -5.898771349824866e+01, -3.054654861614420e+03, -6.326372563307543e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_rpw86_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rpw86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.454817845873578e-02, -1.518388873412353e-02, -1.611781195508267e-02, -1.749087918992097e-02, -1.949058088882937e-02, -2.229331029030872e-02, -2.579092585160751e-02, -2.888837024386160e-02, -2.918070630007470e-02, -2.660460338285025e-02, -4.155471625742926e-02, -5.895013125977577e-01, -7.984378454265509e-01, -1.058899548343910e+00, -8.016594750598949e-01, -4.100494749346570e-01, -1.837369385150096e+00, -1.959286569943052e+01, 1.043720103259600e+04, 2.321398482436551e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_rpw86_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rpw86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.153693354231457e-08, 5.780321197059472e-08, 6.780550903813484e-08, 8.428135264527614e-08, 1.121105216155706e-07, 1.580251291744049e-07, 2.135632469042269e-07, 9.157454116699689e-08, -2.051963150738350e-06, -2.751592972405503e-05, -5.074594636179661e-04, 1.419298619193582e-02, 8.476372371527775e-02, 8.503690240357013e-02, -9.731627053539526e-01, -3.330440025308713e+01, -2.704685231795053e+03, -1.137477770386133e+06, -8.295358757247780e+09, -1.310347561672228e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_rpw86_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rpw86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.032513046864548e-13, -1.057823230304569e-13, -9.923596691177664e-14, -5.131359831289503e-14, 1.871312993901859e-13, 1.439176410105894e-12, 9.536430763033330e-12, 8.196581563674494e-11, 1.110529236815275e-09, 3.154128133081283e-08, 3.615111246652261e-06, 6.903460975795540e-04, -1.040837588743939e-02, 6.371004162896150e-02, 2.977332014437351e+00, 4.515954078774373e+02, 4.847324560012743e+05, 8.069724308290521e+09, 6.141072994459250e+15, 7.390014091594167e+23]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
