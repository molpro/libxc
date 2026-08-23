
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_epc18_2_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc18_2", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.471064279338981e-03, -1.565074041495779e-03, -1.710889014073947e-03, -1.944688925511848e-03, -2.337982629470702e-03, -3.047277068555189e-03, -4.463807518597526e-03, -7.757954088206216e-03, -1.745229709564468e-02, -5.781537402228690e-02, -1.216966275013792e-01, -3.602509575903594e-02, -2.122282968612278e-02, -1.051516186694669e-02, -2.936512069804863e-03, -4.273174801832018e-04, -2.612695816090459e-05, -4.647357315914010e-07, -1.433658491812496e-09, -4.218012228014222e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_epc18_2_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc18_2", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.694702905560952e-05, 1.692342945210492e-05, 1.916874472076345e-05, 1.911520375366369e-05, 2.288836403624679e-05, 2.276188891388292e-05, 2.954500094755731e-05, 2.922837067572325e-05, 4.265658440241372e-05, 4.179481373876306e-05, 7.229760157277089e-05, 6.965253992603395e-05, 1.539218656438095e-04, 1.442712021523905e-04, 4.511140968264622e-04, 4.059796727488926e-04, 2.018300162049681e-03, 1.717209665254896e-03, 1.071944064276981e-02, 7.188132923723755e-03, -1.433328437516282e-01, -2.379568147011284e-01, -5.177607054783658e-02, -1.641232026332626e-01, -2.948403362098661e-02, -1.029743812072783e-01, -1.430184683980672e-02, -4.813055355165921e-02, -3.783586341230269e-03, -1.413937407947652e-02, -5.177231833265178e-04, -2.488312252074715e-03, -2.961418300654801e-05, -2.223260868112895e-04, -4.943516548740975e-07, -7.758359015419896e-06, -1.462879851778900e-09, -7.177202372264656e-08, -4.236139317199589e-13, -9.857119107187853e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_epc18_2_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc18_2", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.223664944244171e-06, -5.602330419540227e-06, 5.224192052103121e-06, 5.890206955725339e-06, -6.345554493721929e-06, 5.891478315826944e-06, 6.997261342093638e-06, -7.590950963091669e-06, 7.000540680061186e-06, 8.954066065464490e-06, -9.823557836477356e-06, 8.963381055609439e-06, 1.273273152662160e-05, -1.423732075813633e-05, 1.276312017138989e-05, 2.099496569949548e-05, -2.430002787686219e-05, 2.111588890152627e-05, 4.240450127468957e-05, -5.259401396512268e-05, 4.304411563139491e-05, 1.110049510794609e-04, -1.614695723172421e-04, 1.160873040370876e-04, 3.712747548885434e-04, -8.330057805318572e-04, 4.435262371360114e-04, 3.707504203378182e-03, -6.056921801319705e-03, 6.477888223070563e-03, 1.536219051572864e-01, -4.733215634050519e-02, 3.039465474727578e-01, -1.243748863711157e-02, -3.767983942720118e-01, -9.145172927254368e-02, -1.160449436606645e-02, -3.507784138033208e-01, -9.235626166012052e-02, -7.371400321395412e-03, -3.096206227062593e-01, -5.310383295158576e-02, -2.174182088793348e-03, -2.730888296036463e-01, -1.812727737466096e-02, -2.926897095188488e-04, -2.591691904212650e-01, -3.623485819941108e-03, -1.536786842818623e-05, -2.566213549059808e-01, -3.886014606852275e-04, -2.246145779964192e-07, -2.564160788061335e-01, -1.860339890654285e-05, -5.645259553936940e-10, -2.564102965223350e-01, -2.951114278490665e-07, -1.399655847068016e-13, -2.564102564515640e-01, -9.218224317944808e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
