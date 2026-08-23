
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_b88m_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88m", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.332727097230486e+00, -4.251100967243407e+00, -4.136815096071833e+00, -3.978692372396224e+00, -3.763628433064524e+00, -3.478218051909139e+00, -3.112538357259726e+00, -2.666824916412755e+00, -2.159823307956275e+00, -1.629676142198740e+00, -1.098470053879435e+00, -6.703083878820723e-01, -5.658766188720107e-01, -4.766224069575272e-01, -3.532805894062748e-01, -2.352510887220527e-01, -1.476463636047966e-01, -9.110870769334271e-02, -5.851425186317021e-02, -4.057814003978872e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_b88m_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88m", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.370696275339558e+00, -5.257031048606195e+00, -5.097738210492872e+00, -4.877043800108506e+00, -4.576276634561950e+00, -4.175989216695603e+00, -3.661165853988101e+00, -3.031258976995149e+00, -2.316480234203611e+00, -1.599401076276057e+00, -1.028384627599033e+00, -7.999471225236354e-01, -7.137688349091961e-01, -5.563487498584190e-01, -3.635010208913216e-01, -1.973573513479739e-01, -9.357820454451050e-02, -4.079329935170851e-02, -1.604666020413897e-02, -6.641362446640976e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b88m_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88m", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.359233286289138e-06, -4.698730161161958e-06, -5.232075071135539e-06, -6.102480655461704e-06, -7.602051306945980e-06, -1.039146944003775e-05, -1.616997779350258e-05, -3.006927088912788e-05, -7.107185672013644e-05, -2.307803564119353e-04, -1.161908601262809e-03, -7.526598730577250e-03, -1.513290009072468e-02, -2.940537583491879e-02, -1.013305210422710e-01, -6.228184186326083e-01, -7.001520185306019e+00, -1.818140269628952e+02, -1.687303734495856e+04, -1.003529921632156e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b88m_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88m", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.199965800911879e-02, -1.253433955502639e-02, -1.334396461600114e-02, -1.459729701638346e-02, -1.659911614859474e-02, -1.993936221393264e-02, -2.585645007159619e-02, -3.718579293802306e-02, -6.090800665418669e-02, -1.147748859331659e-01, -2.577831003471708e-01, -5.431085701536191e-01, -6.735074513598089e-01, -1.117163296419804e+00, -2.365378495725276e+00, -5.614087568070839e+00, -7.037073336066801e+00, 1.614913202109553e+02, 1.829158850097146e+04, 1.039130925079775e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b88m_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88m", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.149397259864649e-08, 2.436433554837359e-08, 2.915198908135402e-08, 3.766203357830582e-08, 5.421231376811612e-08, 9.071702117706162e-08, 1.864270709388170e-07, 5.017678543262688e-07, 1.872544836356000e-06, 9.791527289505231e-06, 1.182917740851426e-04, 9.032664001739996e-03, 3.524341557766523e-02, 9.247949547655547e-02, 5.247198075323007e-01, -1.981016450292616e-01, -1.676145517675634e+03, -1.315923806061395e+06, -1.007909504342156e+10, -3.409457156793232e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b88m_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88m", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.176128913416446e-13, 1.466087261394591e-13, 2.011218187489643e-13, 3.163563076505718e-13, 6.046142960563471e-13, 1.522518172828285e-12, 5.648878229276625e-12, 3.591261554312379e-11, 4.770617659215422e-10, 1.706560947642324e-08, 2.253286521808692e-06, 5.754241854721072e-04, 5.137527632670556e-03, 3.383924842817817e-02, 1.405717126801922e+00, 3.830414152348838e+02, 7.580293428553171e+05, 1.993777178554978e+10, 2.419012708500568e+16, 8.048597240192698e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
