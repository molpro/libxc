
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_k_tf_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_tf", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.122434916346732e+01, 8.757610815910729e+01, 8.258853162441982e+01, 7.591957066997570e+01, 6.728126774477821e+01, 5.658828036716444e+01, 4.417881790955630e+01, 3.103535622733318e+01, 1.880747831443857e+01, 9.384616282054603e+00, 4.047656784848406e+00, 2.417033911662058e+00, 1.872303981750779e+00, 1.199060090948408e+00, 5.633303926790458e-01, 1.833684904934030e-01, 3.783016817364134e-02, 4.202812020760790e-03, 1.914250794214317e-04, 2.399672222533025e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_k_tf_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_tf", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.520418156857921e+02, 1.520393481623975e+02, 1.459627077521162e+02, 1.459576526469346e+02, 1.376527089140969e+02, 1.376423959211241e+02, 1.265430754249697e+02, 1.265221575480698e+02, 1.121564867578835e+02, 1.121143938742365e+02, 9.435568134450131e+01, 9.427186401258292e+01, 7.371356999037809e+01, 7.354888010535926e+01, 5.188411719507305e+01, 5.156559917660869e+01, 3.164413492793039e+01, 3.103868786638040e+01, 1.617379350755391e+01, 1.504732924144781e+01, 7.507451245095379e+00, 5.547464877272444e+00, 4.619260554694179e+00, 2.097975379129060e+00, 3.565973302822790e+00, 1.520378514190401e+00, 2.287973528196824e+00, 1.007370638522071e+00, 1.070802249095203e+00, 4.428036977902911e-01, 3.440392543786913e-01, 1.206986848642083e-01, 6.904925429235756e-02, 1.800788230583348e-02, 7.376036064007664e-03, 1.176700099981574e-03, 3.250502528190386e-04, 2.425415452686181e-05, 4.016185301672430e-06, 1.061599151141599e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_k_tf_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_tf", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.131965575377418e+00, 3.736078471755051e-131, 1.131974760960756e+00, 1.155297377597774e+00, 3.736078471755051e-131, 1.155317383740267e+00, 1.189658637132643e+00, 0.000000000000000e+00, 1.189703204474252e+00, 1.240782188939518e+00, 1.245359490585017e-131, 1.240884753806082e+00, 1.317960956466962e+00, -1.245359490585017e-131, 1.318208344733182e+00, 1.436913799925862e+00, -2.490718981170034e-131, 1.437552439691679e+00, 1.625702302395359e+00, 6.226797452925084e-131, 1.627521412449251e+00, 1.937749026602980e+00, 4.981437962340068e-131, 1.943724500630730e+00, 2.481236318383868e+00, 0.000000000000000e+00, 2.505319198427603e+00, 3.470633833229738e+00, 4.981437962340068e-131, 3.598197781187977e+00, 5.094111926975971e+00, 4.981437962340068e-131, 5.926079352994392e+00, 6.494242676901099e+00, -4.981437962340068e-131, 9.636394023844645e+00, 7.391382876755804e+00, -9.962875924680135e-131, 1.131980332834860e+01, 9.227610308533212e+00, 0.000000000000000e+00, 1.390657233057770e+01, 1.348838973052547e+01, 3.985150369872054e-130, 2.097534552933759e+01, 2.379637171854444e+01, -3.985150369872054e-130, 4.017570201512213e+01, 5.311720894501711e+01, 0.000000000000000e+00, 1.040119938017040e+02, 1.625186580036551e+02, -3.188120295897643e-129, 4.068945267168556e+02, 7.741756174192760e+02, 2.550496236718115e-128, 2.834142437607261e+03, 6.964787526563126e+03, 4.080793978748983e-127, 4.283852036108034e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
