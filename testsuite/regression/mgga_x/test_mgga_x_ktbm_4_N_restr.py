
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_4_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_4", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.778727640141920e+00, -4.681967639969801e+00, -4.546295120730893e+00, -4.358159828112547e+00, -4.101359659460334e+00, -3.758543519982597e+00, -3.314788722228469e+00, -2.763743569139504e+00, -2.116444480943563e+00, -1.424640461727861e+00, -8.408271613607438e-01, -5.715055502651302e-01, -5.656513665038410e-01, -4.740244545955820e-01, -3.173251058334777e-01, -1.720630177352446e-01, -7.485634435148560e-02, -2.403656946102797e-02, -5.001254969034039e-03, -5.548928506117316e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_4_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.184027752582383e+00, -6.052848894908491e+00, -5.868923414419012e+00, -5.613920287732611e+00, -5.266031824066641e+00, -4.802318377029265e+00, -4.204598133384477e+00, -3.470814177990441e+00, -2.630748977280655e+00, -1.760107535017327e+00, -1.064344616883528e+00, -7.987535707495439e-01, -8.303978765895977e-01, -6.479308138521100e-01, -4.067631137810155e-01, -2.030625451245811e-01, -8.604782988180586e-02, -2.746044059580166e-02, -5.673542597606398e-03, -6.263910830487249e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_4_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.548519314974676e-06, -6.018542812713638e-06, -6.763452241227083e-06, -7.994549357786216e-06, -1.015393027175525e-05, -1.427165458750711e-05, -2.307410775150750e-05, -4.482628347557086e-05, -1.066879544878033e-04, -2.831538479545828e-04, -7.151252045753263e-04, -2.945810115426906e-03, -1.343917976102121e-02, -3.487891544337637e-02, -1.215173713477634e-01, -4.861428750623791e-01, -2.588349613490083e+00, -2.768810656923481e+01, -7.224171184649919e+02, -6.397534207688925e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_4_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.042790765015895e-03, 8.234211049589980e-03, 8.517266764779523e-03, 8.940490203054619e-03, 9.582444943184502e-03, 1.057192735469845e-02, 1.210930999754275e-02, 1.439010246942443e-02, 1.675304175246400e-02, 1.477494629085275e-02, 6.656552602574008e-03, 6.399588468776935e-03, 4.475183026550845e-02, 6.416312139638058e-02, 6.988118747817638e-02, 4.397370150162595e-02, 1.882354793104491e-02, 6.712730904034793e-03, 1.594489132412368e-03, 1.941651658191482e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_4_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.455495310233273e-02, -1.525969119554928e-02, -1.633556706681337e-02, -1.802128743329025e-02, -2.076236367640267e-02, -2.545874031043336e-02, -3.409979554798096e-02, -5.148615460734650e-02, -8.981909682939425e-02, -1.737504285207141e-01, -3.117517993869960e-01, -7.845651421912924e-01, -8.725181875771453e-01, -1.437288233056704e+00, -3.528397231460097e+00, -7.822360855847815e+00, -3.371463533794215e+01, -3.481690610770274e+02, -8.288366839047143e+03, -6.834196102032701e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_4_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.371244949660765e-08, 5.041430116067603e-08, 6.185667372958658e-08, 8.289660563572102e-08, 1.258753759651976e-07, 2.275820541832278e-07, 5.211321769516222e-07, 1.598881984890085e-06, 6.320884614146283e-06, 2.034001445497820e-05, -5.935672231252570e-05, -2.159974846596859e-03, 2.422100429342584e-02, 1.507216039043801e-01, 8.932400554259400e-01, 2.996632637442447e+00, 7.464851996671881e+02, 3.846719093651897e+05, 1.210467229776315e+09, 8.040535650084753e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_4_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.512350891408969e-05, -2.759205558552549e-05, -3.155514158440970e-05, -3.821748608161799e-05, -5.014619696762592e-05, -7.331547437538694e-05, -1.224082075790953e-04, -2.271016662755761e-04, -3.224278899454343e-04, 6.199312699676620e-04, 3.558951500968278e-03, 3.324348831742640e-02, 5.341777325593646e-02, 1.194428434795107e-02, 3.454004206913934e-01, 9.884392846031100e-01, -5.013186521565121e+00, -9.324068767376025e+01, -2.671600472075513e+03, -2.440300322618367e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_4_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.807495166338228e-14, -9.934563638393911e-14, -1.403834823345196e-13, -2.304429811229716e-13, -4.682638677678348e-13, -1.286877785570426e-12, -5.391729881431909e-12, -4.003383918496256e-11, -6.101193646041991e-10, -1.957000410425090e-08, -1.165496332120753e-06, -9.042420117780589e-05, -1.769843491990901e-03, -2.497314276387203e-02, -1.429713308427504e+00, -3.151288631769285e+02, -3.427339660773334e+05, -4.109918628948270e+09, -1.492254613076720e+15, -7.647845183615427e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_4_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.189625503849712e-10, 1.446306348724930e-10, 1.915230552098111e-10, 2.866952641867651e-10, 5.114488297396228e-10, 1.171052444345240e-09, 3.805151243519742e-09, 1.980372095550901e-08, 1.792422499931708e-07, 2.417963088092990e-06, 3.428111921376164e-05, 8.388563492514249e-04, 9.606944693410681e-03, 7.845215792063899e-02, 1.887708736263090e+00, 7.611992829599640e+01, 6.030218791020918e+03, 2.254932968121755e+06, 7.347655260592108e+09, 5.156693739889299e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_4_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.278843911650607e-08, -3.315031702993721e-08, -5.269047755132473e-08, -9.351335753044032e-08, -1.913220863981013e-07, -4.722951898659925e-07, -1.493628852345704e-06, -6.420714527726859e-06, -3.664376170075300e-05, -1.954544053561879e-04, -5.599377786633402e-04, -4.106987777835891e-03, -4.602072659519790e-02, -1.889268083618552e-01, -1.673066065266764e+00, -1.123565060107627e+01, -6.962494924563156e+01, -8.518121706776481e+02, -2.516528947140517e+04, -2.425652895790081e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
