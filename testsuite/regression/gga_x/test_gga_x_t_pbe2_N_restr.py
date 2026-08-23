
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_t_pbe2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_t_pbe2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.384717722332899e+00, -4.304716856519615e+00, -4.192855628149237e+00, -4.038409265068316e+00, -3.829051387611638e+00, -3.552796414890232e+00, -3.202490859784542e+00, -2.784083324141793e+00, -2.327638066828704e+00, -1.879024250601524e+00, -1.326195791505138e+00, -6.860726553199118e-01, -5.703617215621988e-01, -4.918678306930215e-01, -3.917749067763302e-01, -3.255125324383832e-01, -3.361925370842526e-01, -2.574939214472610e-01, -6.646653274641878e-02, -7.438220302306154e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_t_pbe2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_t_pbe2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.257490140345934e+00, -5.140055004570969e+00, -4.975152134297230e+00, -4.745985644382040e+00, -4.432155770840700e+00, -4.011143325758168e+00, -3.462196266380606e+00, -2.773812315557188e+00, -1.957861794916053e+00, -1.098620050432395e+00, -5.895133215568894e-01, -7.650764539157597e-01, -7.042088153196114e-01, -5.226564111482775e-01, -2.833837559208250e-01, -4.338531244983509e-02, 5.703450953949344e-02, -2.036375617594776e-01, -8.647296335696511e-02, -9.914497295041270e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_t_pbe2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_t_pbe2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.317712607074491e-06, -6.852788285433830e-06, -7.701659403668617e-06, -9.107240596600590e-06, -1.158206306841554e-05, -1.634053516322194e-05, -2.671786544735864e-05, -5.379133011879723e-05, -1.445520325629898e-04, -5.660837001501548e-04, -3.139534438238146e-03, -1.201136384960727e-02, -2.090624768796492e-02, -4.947499134254397e-02, -2.251841472272009e-01, -2.091744690737365e+00, -3.425332047080018e+01, -3.147695889456455e+02, -5.851241200220445e+02, -6.617437136936049e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_t_pbe2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_t_pbe2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.409669983538638e-02, -1.483499180295175e-02, -1.597119071302599e-02, -1.777361468864194e-02, -2.076278278397566e-02, -2.605531764374549e-02, -3.637988475384068e-02, -5.961506593937110e-02, -1.234933528508112e-01, -3.398134814559881e-01, -9.380126132814375e-01, -7.250100374747670e-01, -7.511808242958281e-01, -1.617383125436595e+00, -5.712190819494394e+00, -3.280941024489025e+01, 9.874157927494747e+01, 1.006979109218480e+04, -7.134733050462074e+04, -8.527554894253636e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_t_pbe2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_t_pbe2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.625570800951135e-08, 5.330539420768878e-08, 6.535090047188929e-08, 8.754563545499373e-08, 1.331270097769227e-07, 2.425248072155543e-07, 5.708372592619085e-07, 1.926046399084243e-06, 1.066903091437238e-05, 1.117438972173912e-04, 2.172575061192109e-03, 2.513500421977388e-02, 6.697925034346017e-02, 2.978586465852430e-01, 4.053878162059443e+00, 1.690349724128270e+02, -5.381286005318780e+03, -2.744351461580957e+07, -8.051615610835741e+09, -6.854476680433736e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_t_pbe2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_t_pbe2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.378127110868451e-15, 1.069753004585102e-14, 1.519695921513089e-14, 2.515697757005064e-14, 5.183652912365365e-14, 1.460023050714980e-13, 6.415076908885392e-13, 5.286316080603547e-12, 1.046733157882036e-10, 6.558842153346450e-09, 1.153267455342567e-06, 5.807296518087008e-05, 3.025491105374265e-04, 4.081734450051489e-03, 4.028202211138836e-01, 3.777425959623596e+02, 3.517394445276642e+06, 9.122471313585789e+10, 2.935893791793940e+15, 1.932477365993103e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
