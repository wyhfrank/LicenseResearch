/*******************************************************************************
 * Copyright (c) 2004, 2009 Tasktop Technologies and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Tasktop Technologies - initial API and implementation
 *******************************************************************************/

package org.eclipse.mylyn.internal.commons.workbench;

import org.eclipse.osgi.util.NLS;

public class Messages extends NLS {

	private static final String BUNDLE_NAME = "org.eclipse.mylyn.internal.commons.workbench.messages"; //$NON-NLS-1$

	static {
		// load message values from bundle file
		reloadMessages();
	}

	public static void reloadMessages() {
		NLS.initializeMessages(BUNDLE_NAME, Messages.class);
	}

	public static String WorkbenchUtil_Browser_Initialization_Failed;

	public static String WorkbenchUtil_Invalid_URL_Error;

	public static String WorkbenchUtil_No_URL_Error;

	public static String WorkbenchUtil_Open_Location_Title;

	public static String AbstractFilteredTree_Find;

	public static String DatePicker_Choose_Date;

	public static String DatePicker_Clear;

	public static String DateSelectionDialog_Date_Selection;

	public static String DatePickerPanel_Today;

	public static String TextControl_FindToolTip;

	public static String TextControl_AccessibleListenerFindButton;

	public static String PropertiesAction_Properties;

}
