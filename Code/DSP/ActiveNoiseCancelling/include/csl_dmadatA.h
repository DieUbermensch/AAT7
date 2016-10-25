/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... DMA
* FILENAME...... csl_dmadatA.h
* DATE CREATED.. Wed 06/27/2001 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*  CREATED:    06/27/2001 For new CSL Initialization model
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the DMA module)
*       Reserved Area for DMA Data 
*
*
\******************************************************************************/
#ifndef _DMA_DATA_H_
#define _DMA_DATA_H_

#define CSL_DMADATAINIT\
{  /* DMA Channel 0 Handle Initialization Data */\
    0x0012u,      /*DMA0_EventId*/\
    0x0000u,      /*DMA0_DmaChaNum*/\
    0x0E00u,      /*DMA0_DmaGcrAddr*/\
    0x0C00u,      /*DMA0_DmaCsdpAddr*/\
    0x0C01u,      /*DMA0_DmaCcrAddr*/\
    0x0C02u,      /*DMA0_DmaCicrAddr*/\
    0x0C03u,      /*DMA0_DmaCsrAddr*/\
    0x0C04u,      /*DMA0_DmaCssalAddr*/\
    0x0C05u,      /*DMA0_DmaCssauAddr*/\
    0x0C06u,      /*DMA0_DmaCdsalAddr*/\
    0x0C07u,      /*DMA0_DmaCdsauAddr*/\
    0x0C08u,      /*DMA0_DmaCenAddr*/\
    0x0C09u,      /*DMA0_DmaCfnAddr*/\
    0x0C0Au,      /*DMA0_DmaCfiAddr*/\
    0x0C0Bu,      /*DMA0_DmaCeiAddr*/\
   /* DMA Channel #1 Handle Initialization Data*/\
    0x0009u,      /*DMA1_EventId*/\
    0x0001u,      /*DMA1_DmaChaNum*/\
    0x0E00u,      /*DMA1_DmaGcrAddr*/\
    0x0C20u,      /*DMA1_DmaCsdpAddr*/\
    0x0C21u,      /*DMA1_DmaCcrAddr*/\
    0x0C22u,      /*DMA1_DmaCicrAddr*/\
    0x0C23u,      /*DMA1_DmaCsrAddr*/\
    0x0C24u,      /*DMA1_DmaCssalAddr*/\
    0x0C25u,      /*DMA1_DmaCssauAddr*/\
    0x0C26u,      /*DMA1_DmaCdsalAddr*/\
    0x0C27u,      /*DMA1_DmaCdsauAddr*/\
    0x0C28u,      /*DMA1_DmaCenAddr*/\
    0x0C29u,      /*DMA1_DmaCfnAddr*/\
    0x0C2Au,      /*DMA1_DmaCfiAddr*/\
    0x0C2Bu,      /*DMA1_DmaCeiAddr*/\
   /* DMA Channel #2 Handle Initialization Data*/\
    0x0014u,      /*DMA2_EventId*/\
    0x0002u,      /*DMA2_DmaChaNum*/\
    0x0E00u,      /*DMA2_DmaGcrAddr*/\
    0x0C40u,      /*DMA2_DmaCsdpAddr*/\
    0x0C41u,      /*DMA2_DmaCcrAddr*/\
    0x0C42u,      /*DMA2_DmaCicrAddr*/\
    0x0C43u,      /*DMA2_DmaCsrAddr*/\
    0x0C44u,      /*DMA2_DmaCssalAddr*/\
    0x0C45u,      /*DMA2_DmaCssauAddr*/\
    0x0C46u,      /*DMA2_DmaCdsalAddr*/\
    0x0C47u,      /*DMA2_DmaCdsauAddr*/\
    0x0C48u,      /*DMA2_DmaCenAddr*/\
    0x0C49u,      /*DMA2_DmaCfnAddr*/\
    0x0C4Au,      /*DMA2_DmaCfiAddr*/\
    0x0C4Bu,      /*DMA2_DmaCeiAddr*/\
   /* DMA Channel #3 Handle Initialization Data*/\
    0x0015u,      /*DMA3_EventId*/\
    0x0003u,      /*DMA3_DmaChaNum*/\
    0x0E00u,      /*DMA3_DmaGcrAddr*/\
    0x0C60u,      /*DMA3_DmaCsdpAddr*/\
    0x0C61u,      /*DMA3_DmaCcrAddr*/\
    0x0C62u,      /*DMA3_DmaCicrAddr*/\
    0x0C63u,      /*DMA3_DmaCsrAddr*/\
    0x0C64u,      /*DMA3_DmaCssalAddr*/\
    0x0C65u,      /*DMA3_DmaCssauAddr*/\
    0x0C66u,      /*DMA3_DmaCdsalAddr*/\
    0x0C67u,      /*DMA3_DmaCdsauAddr*/\
    0x0C68u,      /*DMA3_DmaCenAddr*/\
    0x0C69u,      /*DMA3_DmaCfnAddr*/\
    0x0C6Au,      /*DMA3_DmaCfiAddr*/\
    0x0C6Bu,      /*DMA3_DmaCeiAddr*/\
   /* DMA Channel #4 Handle Initialization Data*/\
    0x000Eu,      /*DMA4_EventId*/\
    0x0004u,      /*DMA4_DmaChaNum*/\
    0x0E00u,      /*DMA4_DmaGcrAddr*/\
    0x0C80u,      /*DMA4_DmaCsdpAddr*/\
    0x0C81u,      /*DMA4_DmaCcrAddr*/\
    0x0C82u,      /*DMA4_DmaCicrAddr*/\
    0x0C83u,      /*DMA4_DmaCsrAddr*/\
    0x0C84u,      /*DMA4_DmaCssalAddr*/\
    0x0C85u,      /*DMA4_DmaCssauAddr*/\
    0x0C86u,      /*DMA4_DmaCdsalAddr*/\
    0x0C87u,      /*DMA4_DmaCdsauAddr*/\
    0x0C88u,      /*DMA4_DmaCenAddr*/\
    0x0C89u,      /*DMA4_DmaCfnAddr*/\
    0x0C8Au,      /*DMA4_DmaCfiAddr*/\
    0x0C8Bu,      /*DMA4_DmaCeiAddr*/\
   /* DMA Channel#5 Handle Initialization Data*/\
    0x000Fu,      /*DMA5_EventId*/\
    0x0005u,      /*DMA5_DmaChaNum*/\
    0x0E00u,      /*DMA5_DmaGcrAddr*/\
    0x0CA0u,      /*DMA5_DmaCsdpAddr*/\
    0x0CA1u,      /*DMA5_DmaCcrAddr*/\
    0x0CA2u,      /*DMA5_DmaCicrAddr*/\
    0x0CA3u,      /*DMA5_DmaCsrAddr*/\
    0x0CA4u,      /*DMA5_DmaCssalAddr*/\
    0x0CA5u,      /*DMA5_DmaCssauAddr*/\
    0x0CA6u,      /*DMA5_DmaCdsalAddr*/\
    0x0CA7u,      /*DMA5_DmaCdsauAddr*/\
    0x0CA8u,      /*DMA5_DmaCenAddr*/\
    0x0CA9u,      /*DMA5_DmaCfnAddr*/\
    0x0CAAu,      /*DMA5_DmaCfiAddr*/\
    0x0CABu       /*DMA5_DmaCeiAddr*/\
}
#endif
