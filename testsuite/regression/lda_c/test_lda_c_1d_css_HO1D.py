
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_1d_css_HO1D_2_zk():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_1d_css", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.791391965038056e-03, -5.791391988149594e-03, -5.791392582037601e-03, -5.791396392816529e-03, -5.791415801962189e-03, -5.791505389563402e-03, -5.791895200745272e-03, -5.793512621648035e-03, -5.799901131346440e-03, -5.823692069378851e-03, -5.906171486260866e-03, -6.170437265483605e-03, -6.962918197741927e-03, -9.298340094577208e-03, -1.669194860396165e-02, -3.275541146994930e-02, -1.324918516741392e-02, -7.671118576284409e-04, -4.874064427363432e-06, -8.300012940621115e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_1d_css_HO1D_2_vrho():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_1d_css", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.874920986568860e-03, 3.826531424787260e-03, 3.889846358203880e-03, 3.811393899625791e-03, 3.913878209418760e-03, 3.786806624166163e-03, 3.952372645655683e-03, 3.746864402191700e-03, 4.013524453085962e-03, 3.681965049019678e-03, 4.109403695336254e-03, 3.576492594000411e-03, 4.256697203347068e-03, 3.405065612526680e-03, 4.476130211639629e-03, 3.126516833379730e-03, 4.789108457027217e-03, 2.674290487785048e-03, 5.212064933303446e-03, 1.940345210402119e-03, 5.758500074647487e-03, 7.408240973152680e-04, 6.478764808766167e-03, -1.293692694527749e-03, 7.582763901537061e-03, -5.164371480720277e-03, 9.670876104208541e-03, -1.447752038110642e-02, 1.431580986512438e-02, -4.591179695587858e-02, -4.905529581852495e-03, -1.867217293998240e-01, -1.420797926335115e-02, -1.228411585036679e-01, -9.564568834009916e-04, -1.101048369056887e-02, -6.723214958982834e-06, -8.971304339565409e-05, -1.307024033261978e-09, -1.732861931847696e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_1d_css_HO1D_2_v2rho2():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_1d_css", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.510969880204913e-03, -1.257306813116281e-02, 4.736075471690900e-03, 4.441530252833457e-03, -1.257281155204011e-02, 4.806488398155453e-03, 4.329715757214006e-03, -1.257214074657607e-02, 4.920855248578828e-03, 4.150592340773688e-03, -1.257039610010934e-02, 5.106649751950920e-03, 3.865998074100136e-03, -1.256589634103106e-02, 5.408588704871080e-03, 3.419705123371941e-03, -1.255444374365035e-02, 5.899607432867660e-03, 2.733993197492245e-03, -1.252589528698142e-02, 6.699208351970855e-03, 1.712650529483233e-03, -1.245695962453280e-02, 8.005258307069409e-03, 2.583068348216036e-04, -1.229807271807543e-02, 1.015378683732689e-02, -1.694053869676221e-03, -1.195399949660176e-02, 1.375091775422256e-02, -4.162188894106899e-03, -1.125716694686880e-02, 2.003864342516374e-02, -7.241121286185839e-03, -9.876431711797872e-03, 3.216254414100833e-02, -1.161599621380442e-02, -6.706422595236301e-03, 6.050764483656788e-02, -2.033829310291262e-02, 4.215900914679167e-03, 1.515182002961402e-01, -5.202101738039494e-02, 7.960607880727044e-02, 6.526813849613634e-01, 2.628283322726237e-01, 3.087719567966537e-01, 3.621721261125741e+00, -6.659131832079179e-02, -3.932117689048333e+00, 3.530368659457959e+00, -4.559286387801862e-01, -1.087355083936115e+01, 3.362898486364726e+00, -9.101407871300253e-01, -2.229861776540232e+01, 2.729481612700425e+00, -2.272695039424548e+00, -4.130828500886646e+01, 1.446600378001762e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
