
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_rpw92_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rpw92", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.180998797102393e-01, -1.175098656683897e-01, -1.166632985667275e-01, -1.154500649694860e-01, -1.137144277587706e-01, -1.112379910507312e-01, -1.077185219407700e-01, -1.027472593834805e-01, -9.579996428731267e-02, -8.631564731559162e-02, -7.391995775467047e-02, -6.067451396387311e-02, -5.681723835599845e-02, -5.266042198605208e-02, -4.423437953619606e-02, -3.239154275378685e-02, -1.915961175917043e-02, -8.235569044443152e-03, -2.319307033131291e-03, -3.416958012721104e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_rpw92_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rpw92", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.277416570792772e-01, -1.277434522715815e-01, -1.271403301119879e-01, -1.271441439847577e-01, -1.262765492418411e-01, -1.262847468725622e-01, -1.250364289365449e-01, -1.250543491325434e-01, -1.232571282758174e-01, -1.232972736749147e-01, -1.207055342244906e-01, -1.207987351135541e-01, -1.170450157355465e-01, -1.172729732972843e-01, -1.117736934591943e-01, -1.123755138011608e-01, -1.040699865341106e-01, -1.058444181498716e-01, -9.230185664117851e-02, -9.835066479794377e-02, -7.356827309652586e-02, -9.585725216685152e-02, -5.561868756464545e-02, -1.085937422001522e-01, -5.197277290246736e-02, -1.068455148409698e-01, -4.853875431054230e-02, -9.729373079314227e-02, -4.101923072532563e-02, -8.642807622800396e-02, -3.048578370022607e-02, -7.232733644813259e-02, -1.890760321044292e-02, -5.269931090098895e-02, -8.982582661221700e-03, -2.802234429212400e-02, -2.831149400294298e-03, -8.035670175431610e-03, -4.433361439135454e-04, -8.502456102079433e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_rpw92_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rpw92", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.569829427500627e-04, -4.665477295877418e-04, 3.570015318265314e-04, 3.776084694888704e-04, -4.940033195089870e-04, 3.776504427750708e-04, 4.093214256009152e-04, -5.362873934013928e-04, 4.094198967676653e-04, 4.595141318379602e-04, -6.033770163557797e-04, 4.597582186192705e-04, 5.423083270636298e-04, -7.144659447549234e-04, 5.429631684017570e-04, 6.871508226807611e-04, -9.100000789757254e-04, 6.891191634140700e-04, 9.624493308510463e-04, -1.285564382500403e-03, 9.694149660119395e-04, 1.549129554090819e-03, -2.102219858240261e-03, 1.580272667038466e-03, 2.996672960438759e-03, -4.213995473757230e-03, 3.190512866573431e-03, 7.032661915135225e-03, -1.102479640966690e-02, 8.901185891948172e-03, 1.493675588784926e-02, -3.600856827675154e-02, 4.064725726342232e-02, 1.532734464210213e-02, -9.378765017315863e-02, 2.220882747206893e-01, 1.950088653868491e-02, -1.381328428278057e-01, 3.570393372687838e-01, 3.503419368975123e-02, -2.434633030960668e-01, 5.874849466892418e-01, 7.864993478106087e-02, -6.845762895517090e-01, 1.751959348184331e+00, 1.864823933241882e-01, -3.194468573117404e+00, 9.711697169932032e+00, -4.756251691252961e-01, -2.561499241544627e+01, 1.016482273884393e+02, -3.957755555395171e+01, -3.744339768801055e+02, 2.143232240333254e+03, -2.355325459362591e+03, -1.126228265955314e+04, 9.576892402294044e+04, -3.406804954589630e+05, -8.680693087049134e+05, 1.403323308160204e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
