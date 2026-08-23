
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pw86_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw86", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.289934189226829e+00, -4.209894755852409e+00, -4.098018724982516e+00, -3.943611077800662e+00, -3.734349392848824e+00, -3.458018468098060e+00, -3.106097990649221e+00, -2.678785170303681e+00, -2.188114161328078e+00, -1.655526589849433e+00, -1.111659567751762e+00, -6.671174577496757e-01, -5.599854295770889e-01, -4.763423093121960e-01, -3.589516864913946e-01, -2.328877885650175e-01, -1.271476726981063e-01, -5.776151240262650e-02, -2.156166648367076e-02, -5.688076775582028e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pw86_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.267319035238144e+00, -5.148285617198123e+00, -4.981524425117719e+00, -4.750767514325339e+00, -4.437399509301596e+00, -4.024170516581851e+00, -3.504453086589230e+00, -2.898477728468428e+00, -2.262646035236696e+00, -1.656122801284299e+00, -1.101787812287560e+00, -7.689901869605739e-01, -7.074029406076333e-01, -5.318261674272656e-01, -3.641618386326692e-01, -2.277821734501642e-01, -1.205051832746843e-01, -4.974580917203843e-02, -1.733954945038107e-02, -4.550774091874239e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pw86_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.856238307192164e-06, -5.313683739313329e-06, -6.039203233545991e-06, -7.236339255741989e-06, -9.319602643052874e-06, -1.320267017965106e-05, -2.106926175466184e-05, -3.859564941157571e-05, -8.262376613158127e-05, -2.218250145622959e-04, -1.013242427422132e-03, -9.669280465796990e-03, -1.457971019811894e-02, -3.837737483537203e-02, -1.078327293874029e-01, -4.430269631524679e-01, -3.323371870270753e+00, -6.144867553920206e+01, -3.106389063693279e+03, -6.413515700523781e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pw86_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.469326763430062e-02, -1.538644452010416e-02, -1.641514470633625e-02, -1.795046118696103e-02, -2.023711953446061e-02, -2.355022475783020e-02, -2.788936951858522e-02, -3.202173463992003e-02, -3.273233636260512e-02, -2.956056324933243e-02, -4.606426997139447e-02, -6.274409384588634e-01, -7.895903787190398e-01, -1.153178749581595e+00, -8.964114234769696e-01, -4.872467937004646e-01, -2.927013746363152e+00, 2.197249148460708e+01, 1.106530581298378e+04, 2.354620141402908e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pw86_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.246046963516253e-08, 5.942210169843138e-08, 7.073529965517364e-08, 8.990064808655890e-08, 1.238187702236168e-07, 1.850176174490142e-07, 2.822927903891785e-07, 2.771220493077738e-07, -1.547414436789414e-06, -2.578998978975723e-05, -4.861741982675441e-04, 1.713672591067447e-02, 8.028683901762142e-02, 1.200784799054461e-01, -8.625283980331797e-01, -3.231615968112983e+01, -2.574338555163354e+03, -1.210465769319082e+06, -8.522436247964950e+09, -1.328586352459784e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pw86_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.749482310018546e-13, -1.984525862615024e-13, -2.320399185782935e-13, -2.700963728545451e-13, -2.455334230709665e-13, 3.641201032792734e-13, 6.057882453289525e-12, 6.713126613565524e-11, 1.024515231395770e-09, 3.056872497643500e-08, 3.534630401171900e-06, 2.952808716613382e-04, -1.226306164825350e-02, 4.439362317519856e-02, 2.834795718675496e+00, 4.447586513519615e+02, 4.803884267758684e+05, 8.463926999892976e+09, 6.268653809832927e+15, 7.492208694506493e+23]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
