/**************************************************************************
 *                                                                        *
 *  Algorithmic C (tm) DSP Library                                        *
 *                                                                        *
 *  Software Version: 3.2                                                 *
 *                                                                        *
 *  Release Date    : Mon Apr  6 17:58:59 PDT 2020                        *
 *  Release Type    : Production Release                                  *
 *  Release Build   : 3.2.3                                               *
 *                                                                        *
 *  Copyright , Mentor Graphics Corporation,                     *
 *                                                                        *
 *  All Rights Reserved.                                                  *
 *  
 **************************************************************************
 *  Licensed under the Apache License, Version 2.0 (the "License");       *
 *  you may not use this file except in compliance with the License.      * 
 *  You may obtain a copy of the License at                               *
 *                                                                        *
 *      http://www.apache.org/licenses/LICENSE-2.0                        *
 *                                                                        *
 *  Unless required by applicable law or agreed to in writing, software   * 
 *  distributed under the License is distributed on an "AS IS" BASIS,     * 
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or       *
 *  implied.                                                              * 
 *  See the License for the specific language governing permissions and   * 
 *  limitations under the License.                                        *
 **************************************************************************
 *                                                                        *
 *  The most recent version of this package is available at github.       *
 *                                                                        *
 *************************************************************************/
/***********************************************************************************/
/*                   Twiddle Vectors 64 BitWidth used in Butterfly                 */
/***********************************************************************************/

#ifndef _TWIDDLESR_64BITS_H_
#define _TWIDDLESR_64BITS_H_

typedef ac_fixed < 64, 2, true, AC_RND > fxpt;
typedef ac_complex < fxpt > comx_twiddle;

const comx_twiddle Rtw0[1] = {
  comx_twiddle (1.0000000000000000000000000000000000000000000000000000000000000000000000, 0.0000000000000000000000000000000000000000000000000000000000000000000000),
};

const comx_twiddle Rtw1[2] = {
  comx_twiddle (1.0000000000000000000000000000000000000000000000000000000000000000000000, 0.0000000000000000000000000000000000000000000000000000000000000000000000),
  comx_twiddle (0.0000000000000000000000000000000000000000000000000000000000000000000000, -1.0000000000000000000000000000000000000000000000000000000000000000000000),

};

const comx_twiddle Rtw2[4] = {
  comx_twiddle (1.0000000000000000000000000000000000000000000000000000000000000000000000, 0.0000000000000000000000000000000000000000000000000000000000000000000000),
  comx_twiddle (0.7071067811865475727373109293694142252206802368164062500000000000000000, -0.7071067811865474617150084668537601828575134277343750000000000000000000),
  comx_twiddle (0.0000000000000000612303176911188629105708969291299581527709960937500000, -1.0000000000000000000000000000000000000000000000000000000000000000000000),
  comx_twiddle (-0.7071067811865474617150084668537601828575134277343750000000000000000000, -0.7071067811865475727373109293694142252206802368164062500000000000000000),

};

const comx_twiddle Rtw3[8] = {
  comx_twiddle (1.0000000000000000000000000000000000000000000000000000000000000000000000, 0.0000000000000000000000000000000000000000000000000000000000000000000000),
  comx_twiddle (0.9238795325112867384831361050601117312908172607421875000000000000000000, -0.3826834323650897817792326804919866845011711120605468750000000000000000),
  comx_twiddle (0.7071067811865475727373109293694142252206802368164062500000000000000000, -0.7071067811865474617150084668537601828575134277343750000000000000000000),
  comx_twiddle (0.3826834323650898372903839117498137056827545166015625000000000000000000, -0.9238795325112867384831361050601117312908172607421875000000000000000000),
  comx_twiddle (0.0000000000000000612303176911188629105708969291299581527709960937500000, -1.0000000000000000000000000000000000000000000000000000000000000000000000),
  comx_twiddle (-0.3826834323650897262680814492341596633195877075195312500000000000000000, -0.9238795325112867384831361050601117312908172607421875000000000000000000),
  comx_twiddle (-0.7071067811865474617150084668537601828575134277343750000000000000000000, -0.7071067811865475727373109293694142252206802368164062500000000000000000),
  comx_twiddle (-0.9238795325112867384831361050601117312908172607421875000000000000000000, -0.3826834323650898928015351430076407268643379211425781250000000000000000),
};

const comx_twiddle Rtw4[16] = {
  comx_twiddle (1.0000000000000000000000000000000000000000000000000000000000000000000000, 0.0000000000000000000000000000000000000000000000000000000000000000000000),
  comx_twiddle (0.9807852804032304305792422383092343807220458984375000000000000000000000, -0.1950903220161282480837883213098393753170967102050781250000000000000000),
  comx_twiddle (0.9238795325112867384831361050601117312908172607421875000000000000000000, -0.3826834323650897817792326804919866845011711120605468750000000000000000),
  comx_twiddle (0.8314696123025452356714026791451033204793930053710937500000000000000000, -0.5555702330196021776487214083317667245864868164062500000000000000000000),
  comx_twiddle (0.7071067811865475727373109293694142252206802368164062500000000000000000, -0.7071067811865474617150084668537601828575134277343750000000000000000000),
  comx_twiddle (0.5555702330196022886710238708474207669496536254882812500000000000000000, -0.8314696123025452356714026791451033204793930053710937500000000000000000),
  comx_twiddle (0.3826834323650898372903839117498137056827545166015625000000000000000000, -0.9238795325112867384831361050601117312908172607421875000000000000000000),
  comx_twiddle (0.1950903220161283313505151681965799070894718170166015625000000000000000, -0.9807852804032304305792422383092343807220458984375000000000000000000000),
  comx_twiddle (0.0000000000000000612303176911188629105708969291299581527709960937500000, -1.0000000000000000000000000000000000000000000000000000000000000000000000),
  comx_twiddle (-0.1950903220161281925726370900520123541355133056640625000000000000000000, -0.9807852804032304305792422383092343807220458984375000000000000000000000),
  comx_twiddle (-0.3826834323650897262680814492341596633195877075195312500000000000000000, -0.9238795325112867384831361050601117312908172607421875000000000000000000),
  comx_twiddle (-0.5555702330196019556041164833004586398601531982421875000000000000000000, -0.8314696123025454577160076041764114052057266235351562500000000000000000),
  comx_twiddle (-0.7071067811865474617150084668537601828575134277343750000000000000000000, -0.7071067811865475727373109293694142252206802368164062500000000000000000),
  comx_twiddle (-0.8314696123025453466937051416607573628425598144531250000000000000000000, -0.5555702330196021776487214083317667245864868164062500000000000000000000),
  comx_twiddle (-0.9238795325112867384831361050601117312908172607421875000000000000000000, -0.3826834323650898928015351430076407268643379211425781250000000000000000),
  comx_twiddle (-0.9807852804032304305792422383092343807220458984375000000000000000000000, -0.1950903220161286089062713244857150129973888397216796875000000000000000),
};

const comx_twiddle Rtw5[32] = {
  comx_twiddle (1.0000000000000000000000000000000000000000000000000000000000000000000000, 0.0000000000000000000000000000000000000000000000000000000000000000000000),
  comx_twiddle (0.9951847266721969287317506314138881862163543701171875000000000000000000, -0.0980171403295606036287779261328978464007377624511718750000000000000000),
  comx_twiddle (0.9807852804032304305792422383092343807220458984375000000000000000000000, -0.1950903220161282480837883213098393753170967102050781250000000000000000),
  comx_twiddle (0.9569403357322088243819280251045711338520050048828125000000000000000000, -0.2902846772544623310530198523338185623288154602050781250000000000000000),
  comx_twiddle (0.9238795325112867384831361050601117312908172607421875000000000000000000, -0.3826834323650897817792326804919866845011711120605468750000000000000000),
  comx_twiddle (0.8819212643483550495560052695509511977434158325195312500000000000000000, -0.4713967368259976420397094898362411186099052429199218750000000000000000),
  comx_twiddle (0.8314696123025452356714026791451033204793930053710937500000000000000000, -0.5555702330196021776487214083317667245864868164062500000000000000000000),
  comx_twiddle (0.7730104533627369933768136434082407504320144653320312500000000000000000, -0.6343932841636454877942696839454583823680877685546875000000000000000000),
  comx_twiddle (0.7071067811865475727373109293694142252206802368164062500000000000000000, -0.7071067811865474617150084668537601828575134277343750000000000000000000),
  comx_twiddle (0.6343932841636454877942696839454583823680877685546875000000000000000000, -0.7730104533627369933768136434082407504320144653320312500000000000000000),
  comx_twiddle (0.5555702330196022886710238708474207669496536254882812500000000000000000, -0.8314696123025452356714026791451033204793930053710937500000000000000000),
  comx_twiddle (0.4713967368259978085731631836097221821546554565429687500000000000000000, -0.8819212643483549385337028070352971553802490234375000000000000000000000),
  comx_twiddle (0.3826834323650898372903839117498137056827545166015625000000000000000000, -0.9238795325112867384831361050601117312908172607421875000000000000000000),
  comx_twiddle (0.2902846772544623310530198523338185623288154602050781250000000000000000, -0.9569403357322089354042304876202251762151718139648437500000000000000000),
  comx_twiddle (0.1950903220161283313505151681965799070894718170166015625000000000000000, -0.9807852804032304305792422383092343807220458984375000000000000000000000),
  comx_twiddle (0.0980171403295607701622316199063789099454879760742187500000000000000000, -0.9951847266721968177094481688982341438531875610351562500000000000000000),
  comx_twiddle (0.0000000000000000612303176911188629105708969291299581527709960937500000, -1.0000000000000000000000000000000000000000000000000000000000000000000000),
  comx_twiddle (-0.0980171403295606452621413495762681122869253158569335937500000000000000, -0.9951847266721969287317506314138881862163543701171875000000000000000000),
  comx_twiddle (-0.1950903220161281925726370900520123541355133056640625000000000000000000, -0.9807852804032304305792422383092343807220458984375000000000000000000000),
  comx_twiddle (-0.2902846772544621645195661585603374987840652465820312500000000000000000, -0.9569403357322089354042304876202251762151718139648437500000000000000000),
  comx_twiddle (-0.3826834323650897262680814492341596633195877075195312500000000000000000, -0.9238795325112867384831361050601117312908172607421875000000000000000000),
  comx_twiddle (-0.4713967368259976975508607210940681397914886474609375000000000000000000, -0.8819212643483550495560052695509511977434158325195312500000000000000000),
  comx_twiddle (-0.5555702330196019556041164833004586398601531982421875000000000000000000, -0.8314696123025454577160076041764114052057266235351562500000000000000000),
  comx_twiddle (-0.6343932841636453767719672214298043400049209594726562500000000000000000, -0.7730104533627371043991161059238947927951812744140625000000000000000000),
  comx_twiddle (-0.7071067811865474617150084668537601828575134277343750000000000000000000, -0.7071067811865475727373109293694142252206802368164062500000000000000000),
  comx_twiddle (-0.7730104533627369933768136434082407504320144653320312500000000000000000, -0.6343932841636454877942696839454583823680877685546875000000000000000000),
  comx_twiddle (-0.8314696123025453466937051416607573628425598144531250000000000000000000, -0.5555702330196021776487214083317667245864868164062500000000000000000000),
  comx_twiddle (-0.8819212643483549385337028070352971553802490234375000000000000000000000, -0.4713967368259978640843144148675492033362388610839843750000000000000000),
  comx_twiddle (-0.9238795325112867384831361050601117312908172607421875000000000000000000, -0.3826834323650898928015351430076407268643379211425781250000000000000000),
  comx_twiddle (-0.9569403357322088243819280251045711338520050048828125000000000000000000, -0.2902846772544623865641710835916455835103988647460937500000000000000000),
  comx_twiddle (-0.9807852804032304305792422383092343807220458984375000000000000000000000, -0.1950903220161286089062713244857150129973888397216796875000000000000000),
  comx_twiddle (-0.9951847266721968177094481688982341438531875610351562500000000000000000, -0.0980171403295608256733828511642059311270713806152343750000000000000000),
};

const comx_twiddle Rtw6[64] = {
  comx_twiddle (1.0000000000000000000000000000000000000000000000000000000000000000000000, 0.0000000000000000000000000000000000000000000000000000000000000000000000),
  comx_twiddle (0.9987954562051724050064649418345652520656585693359375000000000000000000, -0.0490676743274180149345653489945107139647006988525390625000000000000000),
  comx_twiddle (0.9951847266721969287317506314138881862163543701171875000000000000000000, -0.0980171403295606036287779261328978464007377624511718750000000000000000),
  comx_twiddle (0.9891765099647810144389836750633548945188522338867187500000000000000000, -0.1467304744553617479319029826001496985554695129394531250000000000000000),
  comx_twiddle (0.9807852804032304305792422383092343807220458984375000000000000000000000, -0.1950903220161282480837883213098393753170967102050781250000000000000000),
  comx_twiddle (0.9700312531945439742386838588572572916746139526367187500000000000000000, -0.2429801799032638709441300761682214215397834777832031250000000000000000),
  comx_twiddle (0.9569403357322088243819280251045711338520050048828125000000000000000000, -0.2902846772544623310530198523338185623288154602050781250000000000000000),
  comx_twiddle (0.9415440651830208063088889502978418022394180297851562500000000000000000, -0.3368898533922200511092626129538984969258308410644531250000000000000000),
  comx_twiddle (0.9238795325112867384831361050601117312908172607421875000000000000000000, -0.3826834323650897817792326804919866845011711120605468750000000000000000),
  comx_twiddle (0.9039892931234433381959547659789677709341049194335937500000000000000000, -0.4275550934302820849097770405933260917663574218750000000000000000000000),
  comx_twiddle (0.8819212643483550495560052695509511977434158325195312500000000000000000, -0.4713967368259976420397094898362411186099052429199218750000000000000000),
  comx_twiddle (0.8577286100002721180857179206213913857936859130859375000000000000000000, -0.5141027441932216612840989000687841325998306274414062500000000000000000),
  comx_twiddle (0.8314696123025452356714026791451033204793930053710937500000000000000000, -0.5555702330196021776487214083317667245864868164062500000000000000000000),
  comx_twiddle (0.8032075314806449428672863177780527621507644653320312500000000000000000, -0.5956993044924333569056784654094371944665908813476562500000000000000000),
  comx_twiddle (0.7730104533627369933768136434082407504320144653320312500000000000000000, -0.6343932841636454877942696839454583823680877685546875000000000000000000),
  comx_twiddle (0.7409511253549591058842338497925084084272384643554687500000000000000000, -0.6715589548470183300921121372084598988294601440429687500000000000000000),
  comx_twiddle (0.7071067811865475727373109293694142252206802368164062500000000000000000, -0.7071067811865474617150084668537601828575134277343750000000000000000000),
  comx_twiddle (0.6715589548470183300921121372084598988294601440429687500000000000000000, -0.7409511253549591058842338497925084084272384643554687500000000000000000),
  comx_twiddle (0.6343932841636454877942696839454583823680877685546875000000000000000000, -0.7730104533627369933768136434082407504320144653320312500000000000000000),
  comx_twiddle (0.5956993044924334679279809279250912368297576904296875000000000000000000, -0.8032075314806448318449838552623987197875976562500000000000000000000000),
  comx_twiddle (0.5555702330196022886710238708474207669496536254882812500000000000000000, -0.8314696123025452356714026791451033204793930053710937500000000000000000),
  comx_twiddle (0.5141027441932216612840989000687841325998306274414062500000000000000000, -0.8577286100002721180857179206213913857936859130859375000000000000000000),
  comx_twiddle (0.4713967368259978085731631836097221821546554565429687500000000000000000, -0.8819212643483549385337028070352971553802490234375000000000000000000000),
  comx_twiddle (0.4275550934302821959320795031089801341295242309570312500000000000000000, -0.9039892931234433381959547659789677709341049194335937500000000000000000),
  comx_twiddle (0.3826834323650898372903839117498137056827545166015625000000000000000000, -0.9238795325112867384831361050601117312908172607421875000000000000000000),
  comx_twiddle (0.3368898533922200511092626129538984969258308410644531250000000000000000, -0.9415440651830208063088889502978418022394180297851562500000000000000000),
  comx_twiddle (0.2902846772544623310530198523338185623288154602050781250000000000000000, -0.9569403357322089354042304876202251762151718139648437500000000000000000),
  comx_twiddle (0.2429801799032639819664325386838754639029502868652343750000000000000000, -0.9700312531945439742386838588572572916746139526367187500000000000000000),
  comx_twiddle (0.1950903220161283313505151681965799070894718170166015625000000000000000, -0.9807852804032304305792422383092343807220458984375000000000000000000000),
  comx_twiddle (0.1467304744553617479319029826001496985554695129394531250000000000000000, -0.9891765099647810144389836750633548945188522338867187500000000000000000),
  comx_twiddle (0.0980171403295607701622316199063789099454879760742187500000000000000000, -0.9951847266721968177094481688982341438531875610351562500000000000000000),
  comx_twiddle (0.0490676743274181259568678115101647563278675079345703125000000000000000, -0.9987954562051724050064649418345652520656585693359375000000000000000000),
  comx_twiddle (0.0000000000000000612303176911188629105708969291299581527709960937500000, -1.0000000000000000000000000000000000000000000000000000000000000000000000),
  comx_twiddle (-0.0490676743274180079956714450872823363170027732849121093750000000000000, -0.9987954562051724050064649418345652520656585693359375000000000000000000),
  comx_twiddle (-0.0980171403295606452621413495762681122869253158569335937500000000000000, -0.9951847266721969287317506314138881862163543701171875000000000000000000),
  comx_twiddle (-0.1467304744553616369096005200844956561923027038574218750000000000000000, -0.9891765099647810144389836750633548945188522338867187500000000000000000),
  comx_twiddle (-0.1950903220161281925726370900520123541355133056640625000000000000000000, -0.9807852804032304305792422383092343807220458984375000000000000000000000),
  comx_twiddle (-0.2429801799032638709441300761682214215397834777832031250000000000000000, -0.9700312531945439742386838588572572916746139526367187500000000000000000),
  comx_twiddle (-0.2902846772544621645195661585603374987840652465820312500000000000000000, -0.9569403357322089354042304876202251762151718139648437500000000000000000),
  comx_twiddle (-0.3368898533922199400869601504382444545626640319824218750000000000000000, -0.9415440651830208063088889502978418022394180297851562500000000000000000),
  comx_twiddle (-0.3826834323650897262680814492341596633195877075195312500000000000000000, -0.9238795325112867384831361050601117312908172607421875000000000000000000),
  comx_twiddle (-0.4275550934302818628651721155620180070400238037109375000000000000000000, -0.9039892931234434492182572284946218132972717285156250000000000000000000),
  comx_twiddle (-0.4713967368259976975508607210940681397914886474609375000000000000000000, -0.8819212643483550495560052695509511977434158325195312500000000000000000),
  comx_twiddle (-0.5141027441932216612840989000687841325998306274414062500000000000000000, -0.8577286100002721180857179206213913857936859130859375000000000000000000),
  comx_twiddle (-0.5555702330196019556041164833004586398601531982421875000000000000000000, -0.8314696123025454577160076041764114052057266235351562500000000000000000),
  comx_twiddle (-0.5956993044924333569056784654094371944665908813476562500000000000000000, -0.8032075314806449428672863177780527621507644653320312500000000000000000),
  comx_twiddle (-0.6343932841636453767719672214298043400049209594726562500000000000000000, -0.7730104533627371043991161059238947927951812744140625000000000000000000),
  comx_twiddle (-0.6715589548470184411144145997241139411926269531250000000000000000000000, -0.7409511253549589948619313872768543660640716552734375000000000000000000),
  comx_twiddle (-0.7071067811865474617150084668537601828575134277343750000000000000000000, -0.7071067811865475727373109293694142252206802368164062500000000000000000),
  comx_twiddle (-0.7409511253549588838396289247612003237009048461914062500000000000000000, -0.6715589548470185521367170622397679835557937622070312500000000000000000),
  comx_twiddle (-0.7730104533627369933768136434082407504320144653320312500000000000000000, -0.6343932841636454877942696839454583823680877685546875000000000000000000),
  comx_twiddle (-0.8032075314806448318449838552623987197875976562500000000000000000000000, -0.5956993044924334679279809279250912368297576904296875000000000000000000),
  comx_twiddle (-0.8314696123025453466937051416607573628425598144531250000000000000000000, -0.5555702330196021776487214083317667245864868164062500000000000000000000),
  comx_twiddle (-0.8577286100002720070634154581057373434305191040039062500000000000000000, -0.5141027441932217723064013625844381749629974365234375000000000000000000),
  comx_twiddle (-0.8819212643483549385337028070352971553802490234375000000000000000000000, -0.4713967368259978640843144148675492033362388610839843750000000000000000),
  comx_twiddle (-0.9039892931234433381959547659789677709341049194335937500000000000000000, -0.4275550934302820293986258093354990705847740173339843750000000000000000),
  comx_twiddle (-0.9238795325112867384831361050601117312908172607421875000000000000000000, -0.3826834323650898928015351430076407268643379211425781250000000000000000),
  comx_twiddle (-0.9415440651830206952865864877821877598762512207031250000000000000000000, -0.3368898533922203286650187692430336028337478637695312500000000000000000),
  comx_twiddle (-0.9569403357322088243819280251045711338520050048828125000000000000000000, -0.2902846772544623865641710835916455835103988647460937500000000000000000),
  comx_twiddle (-0.9700312531945439742386838588572572916746139526367187500000000000000000, -0.2429801799032640652331593855706159956753253936767578125000000000000000),
  comx_twiddle (-0.9807852804032304305792422383092343807220458984375000000000000000000000, -0.1950903220161286089062713244857150129973888397216796875000000000000000),
  comx_twiddle (-0.9891765099647810144389836750633548945188522338867187500000000000000000, -0.1467304744553618034430542138579767197370529174804687500000000000000000),
  comx_twiddle (-0.9951847266721968177094481688982341438531875610351562500000000000000000, -0.0980171403295608256733828511642059311270713806152343750000000000000000),
  comx_twiddle (-0.9987954562051724050064649418345652520656585693359375000000000000000000, -0.0490676743274179663623080216439120704308152198791503906250000000000000),
};

#endif // __TWIDDLESR_64BITS_H
