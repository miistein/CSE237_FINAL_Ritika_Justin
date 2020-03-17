import numpy as np
import pyvgg

I= np.loadtxt('I.txt',delimiter=',')
Q= np.loadtxt('Q.txt',delimiter=',')

from collections import defaultdict
correct_snr = defaultdict(int)
cntr_array = defaultdict(int)

# tested against 1000 examples
examples = 100
for i in range(examples):
    i1 = i*1024
    i2 = (i+1)*1024
    IS = I[i1:i2]
    QS = Q[i1:i2]
    x = np.concatenate([IS,QS]).tolist()

    y = pyvgg.compute(x)
    
    preds = np.argmax( y ) 

    correct_ys = np.loadtxt('Y.txt')[i*24:(i+1)*24]

    correct_ys = np.argmax(correct_ys)

    print(correct_ys, preds)

    snr = np.loadtxt('SNR.txt')[i]

    if( preds == correct_ys):
        # correct for this signal to noise ratio
        correct_snr[int(snr)] += 1
        cntr_array[int(snr)] += 1
    else:
        cntr_array[int(snr)] += 1

for z in correct_snr.keys():
    if z in correct_snr:
        print( "accr[" + str(z) + "] = " + str( 100*correct_snr[z]/cntr_array[z] ) )
    else:
        print( "accr[" + str(z) + "] = " + "0" )

