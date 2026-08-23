
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_rtpss_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rtpss", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.765559893938372e+00, -4.669155243381324e+00, -4.534038400413186e+00, -4.346810582622814e+00, -4.091592752775295e+00, -3.751808463365332e+00, -3.314624724651597e+00, -2.779845726882321e+00, -2.175873340098920e+00, -1.578661533443833e+00, -1.039988240139479e+00, -6.497992092011928e-01, -5.606389817179276e-01, -4.823772871748016e-01, -3.454145842379745e-01, -2.277154094743145e-01, -1.309138511945197e-01, -4.238120640772890e-02, -8.774367452886237e-03, -9.701687044429635e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_rtpss_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rtpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.742747981661115e+00, -5.634272953806359e+00, -5.482088064919679e+00, -5.270823131962847e+00, -4.981795024904838e+00, -4.594012497763100e+00, -4.086079831182569e+00, -3.436839365646862e+00, -2.621901429997715e+00, -1.664236644730433e+00, -9.377338510813352e-01, -8.297381503547779e-01, -7.277444160218713e-01, -5.809917192749801e-01, -3.877230980043991e-01, -1.664663654999102e-01, -1.582855816097801e-01, -5.650827521030476e-02, -1.169915660384832e-02, -1.293558272590618e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rtpss_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rtpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.741240331436669e-05, -1.793814374422614e-05, -1.871069401302840e-05, -1.985450818090281e-05, -2.156473720830788e-05, -2.416109170019453e-05, -2.826305988994123e-05, -3.591424701357024e-05, -6.069929868511640e-05, -2.194765378510721e-04, -1.368184453590770e-03, -2.743623306267002e-03, -1.614814638912366e-02, -4.791415942307457e-02, -9.930714103042843e-02, -7.637752576150947e-01, -1.104263534416446e+00, -9.751501713271511e-13, -0.000000000000000e+00, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rtpss_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rtpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.468889925564112e-02, 2.391485114196404e-02, 2.282937483429563e-02, 2.132406954634409e-02, 1.927098867757450e-02, 1.654300822817221e-02, 1.307763814410163e-02, 9.044589797893224e-03, 5.166653623493393e-03, 2.743327848985495e-03, 2.036280896907296e-03, -2.151362311711791e-04, 9.435344967819278e-03, 3.903619778224809e-02, 2.020412348454945e-02, 3.740107650185016e-03, 1.806085458132127e-05, 2.645236890272232e-21, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rtpss_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.927154657815315e-03, -3.950929698873366e-03, -3.986987356066707e-03, -4.049243154546044e-03, -4.187151337507293e-03, -4.606157087707268e-03, -6.263379572276948e-03, -1.407178799865997e-02, -5.382490794007807e-02, -2.187132295274792e-01, -5.586475354443642e-01, -4.431679088311373e-01, -6.981027131737298e-01, -7.630242417583374e-01, -3.198727536202294e+00, -6.489289604956099e+00, 1.003118961866574e+02, -5.852421857996191e+02, -1.365370822982718e+04, -1.116831697629218e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rtpss_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.395600534436827e-07, -1.588067641906989e-07, -1.908674572332924e-07, -2.476326000398875e-07, -3.569003936373157e-07, -5.917195463891027e-07, -1.167336676850776e-06, -2.735446589962374e-06, -6.057496777419861e-06, 1.497425006143796e-05, 6.040714705646843e-04, 7.257309434748335e-03, 3.062416746058432e-02, -1.879707238793714e-01, -4.335562153100644e-01, -5.489726985853048e+00, -1.045557832116981e+04, -2.903519116711752e-06, -0.000000000000000e+00, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rtpss_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.524321137985898e-04, 1.637098021903444e-04, 1.811211062711015e-04, 2.087726434721879e-04, 2.543652089055646e-04, 3.331544594745534e-04, 4.765888390044528e-04, 7.489649653317676e-04, 1.272203858682528e-03, 2.288436196028490e-03, 4.315938024863528e-03, -8.176198840346247e-03, 1.023474559027668e-02, 2.117358767433636e-01, 1.073307107957604e+00, 1.875418130215596e+00, 1.528555606268073e-01, 8.559868959272118e-15, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rtpss_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.565242759087114e-12, 1.954687502232717e-12, 2.676492185552926e-12, 4.164459305903822e-12, 7.722452155063204e-12, 1.815748413164821e-11, 5.843927389745929e-11, 2.801768941009562e-10, 2.160013952041166e-09, 3.193718893405455e-08, 1.979823522098586e-06, -8.917172841929189e-04, -2.526373925375160e-02, 1.426939861543495e-01, 3.779163944348015e+00, 5.754098774367552e+02, 8.097624085272886e+05, 6.633817934707425e-03, 2.964393875047479e-323, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rtpss_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.010110209718963e-09, 3.172657441653865e-09, 3.400071855414853e-09, 3.696867024540048e-09, 3.990490727705876e-09, 3.813207752516759e-09, 6.234993734167354e-10, -2.038491869856304e-08, -1.595825255731046e-07, -1.170398063536288e-06, -6.662097605785528e-06, 8.504650338566209e-04, 3.574029739846902e-02, 6.019876007972044e-02, -9.932923270919597e-01, -9.888164806743116e+00, 7.362899410080673e+00, -1.969244226471107e-11, -0.000000000000000e+00, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rtpss_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.168993437626149e-05, -1.194577930758670e-05, -1.230431031916595e-05, -1.279313161609291e-05, -1.341687597764703e-05, -1.407091596885739e-05, -1.424654300110912e-05, -1.212114904782218e-05, -2.820501960382396e-06, 1.217453091033803e-05, -7.033006497486141e-05, -2.009518404837912e-04, -4.543517455496657e-02, -2.540651636949589e-01, -7.425082507941955e-02, -9.275340918385179e-02, -2.062590521461637e-01, 1.323515521833653e-16, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
