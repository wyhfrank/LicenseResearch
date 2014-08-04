/*******************************************************************************
 * Copyright (c) 2005, 2009 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 * IBM - Initial API and implementation
 *******************************************************************************/

package org.eclipse.mylyn.internal.commons.net;

import org.eclipse.osgi.util.NLS;

public class Messages extends NLS {

	private static final String BUNDLE_NAME = "org.eclipse.mylyn.internal.commons.net.messages";//$NON-NLS-1$

	public static String PollingInputStream_readTimeout;

	public static String PollingInputStream_closeTimeout;

	public static String PollingOutputStream_writeTimeout;

	public static String PollingOutputStream_closeTimeout;

	public static String TimeoutOutputStream_cannotWriteToStream;

	static {
		// load message values from bundle file
		NLS.initializeMessages(BUNDLE_NAME, Messages.class);
	}

}
