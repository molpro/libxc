
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_chachiyo_mod_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_chachiyo_mod", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.171614826533215e-01, -1.165590907345850e-01, -1.156946808086705e-01, -1.144557178407615e-01, -1.126829843082291e-01, -1.101531465447401e-01, -1.065572105158589e-01, -1.014780678182328e-01, -9.438476572002820e-02, -8.472826121574860e-02, -7.227311190916795e-02, -5.950922453076227e-02, -5.578816625930434e-02, -5.167432489385811e-02, -4.356773186984072e-02, -3.238535924123555e-02, -1.985131420051570e-02, -8.753845859482143e-03, -2.211647656495310e-03, -2.553724629085633e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_chachiyo_mod_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_chachiyo_mod", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.270051363286959e-01, -1.270069638997068e-01, -1.263919943534140e-01, -1.263958735266397e-01, -1.255111023563218e-01, -1.255194294877670e-01, -1.242461425696547e-01, -1.242643113830278e-01, -1.224306888797254e-01, -1.224712786151659e-01, -1.198263715264049e-01, -1.199202205468540e-01, -1.160891110826741e-01, -1.163172681117215e-01, -1.107080120334738e-01, -1.113049002272105e-01, -1.028598559438053e-01, -1.045955121061597e-01, -9.097947776064588e-02, -9.677358875358674e-02, -7.254071326175215e-02, -9.335137782270339e-02, -5.557187255443937e-02, -1.033849015549750e-01, -5.212708750373904e-02, -1.010061231992707e-01, -4.870350421662603e-02, -9.166443374920757e-02, -4.149099548039416e-02, -8.044852337430958e-02, -3.149179095215406e-02, -6.618620004281781e-02, -2.028506761509321e-02, -4.808589949959150e-02, -9.814383117223465e-03, -2.691986713198350e-02, -2.743472043946843e-03, -9.248070567552604e-03, -3.336165708111202e-04, -1.660358748451608e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_chachiyo_mod_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_chachiyo_mod", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.633369899692250e-04, -4.750473144799500e-04, 3.633556158269668e-04, 3.839227669866235e-04, -5.026129445538324e-04, 3.839647802771851e-04, 4.155267193017234e-04, -5.450210042619759e-04, 4.156251381054422e-04, 4.654366945000638e-04, -6.122025899490500e-04, 4.656801253158968e-04, 5.474989806161058e-04, -7.231910448405719e-04, 5.481500050449741e-04, 6.903783067577521e-04, -9.178966626230895e-04, 6.923261177235289e-04, 9.600222824429227e-04, -1.290022901623147e-03, 9.668680011400272e-04, 1.528515260611568e-03, -2.093224706544683e-03, 1.558808086827970e-03, 2.908332115943426e-03, -4.147086789484985e-03, 3.093960421791519e-03, 6.663234467406301e-03, -1.066565182904319e-02, 8.412328595386629e-03, 1.384678922206144e-02, -3.426456638051917e-02, 3.737785256464007e-02, 1.218651931687393e-02, -8.268685209612231e-02, 1.839325428443442e-01, 1.476856288065051e-02, -1.198226955012428e-01, 2.897203105688389e-01, 2.673050813742115e-02, -2.120980878778187e-01, 4.792712346007864e-01, 5.603609934895440e-02, -5.883558309593910e-01, 1.408911343979840e+00, 1.038729483886315e-01, -2.733982441898446e+00, 7.888887283868052e+00, -7.893727695399584e-01, -2.359945312849272e+01, 9.632618314832426e+01, -4.372052750880266e+01, -4.328242150133912e+02, 3.250196032542504e+03, -2.466308018654948e+03, -1.875832779963021e+04, 4.140035898678862e+05, -2.725773611179366e+05, -2.684904072243064e+06, 2.916948251225903e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
